// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/MainPlayerState.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

AMainPlayerState::AMainPlayerState()
{
	NetUpdateFrequency = 100.0f;

	abilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(FName("Character Ability System Component"));
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	attributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(FName("Character Attribute Set"));
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}
