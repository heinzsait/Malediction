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

void ABaseCharacter::ApplyEffect(TSubclassOf<UGameplayEffect> effectClass, float level) const
{
	if(GetAbilitySystemComponent() && effectClass)
	{
		FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
		ContextHandle.AddSourceObject(this);
		const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(effectClass, level, ContextHandle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	}
}

void ABaseCharacter::InitializePrimaryAttributes() const
{
	ApplyEffect(defaultPrimaryAttributes, 1.0f);
}

void ABaseCharacter::InitializeSecondaryAttributes() const
{
	ApplyEffect(defaultSecondaryAttributes, 1.0f);
}

void ABaseCharacter::InitializeLifeAttributes() const
{
	ApplyEffect(defaultLifeAttributes, 1.0f);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}
