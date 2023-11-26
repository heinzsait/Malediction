// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

ABaseCharacter::ABaseCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;

	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weaponMesh->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::InitAbilitySystemAndAttribute()
{
	
}

void ABaseCharacter::InitializePrimaryAttributes() const
{
	if(GetAbilitySystemComponent() && defaultPrimaryAttributes)
	{
		const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
		const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(defaultPrimaryAttributes, 1.f, ContextHandle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}
