// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/MainPlayerState.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

AMainPlayerState::AMainPlayerState()
{
	NetUpdateFrequency = 100.0f;

	abilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(FName("Character Ability System Component"));
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	attributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(FName("Character Attribute Set"));
}

void AMainPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerState, level);
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}

void AMainPlayerState::OnRep_Level(int32 oldLevel)
{
	
}
