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
		const FGameplayEffectSpecHandle effectSpecHandle = targetASC->MakeOutgoingSpec(gameplayEffectClass, 1.f, effectContextHandle);
		targetASC->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());
	}
}