// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/CharacterAttributeSet.h"
#include <AbilitySystemGlobals.h>

AEffectActor::AEffectActor()
{
 	PrimaryActorTick.bCanEverTick = false;
	
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));
}

void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActor::ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	UAbilitySystemComponent* targetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(targetActor);
	if (targetASC)
	{
		FGameplayEffectContextHandle effectContextHandle = targetASC->MakeEffectContext();
		effectContextHandle.AddSourceObject(this);
		const FGameplayEffectSpecHandle effectSpecHandle = targetASC->MakeOutgoingSpec(gameplayEffectClass, effectLevel, effectContextHandle);
		FActiveGameplayEffectHandle activeEffectHandle = targetASC->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());

		if (effectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite && infiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{
			activeEffectHandles.Add(activeEffectHandle, targetASC);
		}
	}
}

void AEffectActor::OnOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, instantGameplayEffectClass);
	}
	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, durationGameplayEffectClass);
	}
	if (infiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, infiniteGameplayEffectClass);
	}
}

void AEffectActor::OnEndOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, instantGameplayEffectClass);
	}
	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, durationGameplayEffectClass);
	}
	if (infiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* targetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(targetActor);
		if (!IsValid(targetASC)) return;

		TArray<FActiveGameplayEffectHandle> handlesToRemove;
		for (auto handlePair : activeEffectHandles)
		{
			if (targetASC == handlePair.Value)
			{
				targetASC->RemoveActiveGameplayEffect(handlePair.Key, 1);
				handlesToRemove.Add(handlePair.Key);
			}
		}
		for (FActiveGameplayEffectHandle& handle : handlesToRemove)
		{
			activeEffectHandles.FindAndRemoveChecked(handle);
		}
	}
}
