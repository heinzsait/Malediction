// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAbilitySystemComponent.h"

void UCharacterAbilitySystemComponent::ActorASCSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UCharacterAbilitySystemComponent::EffectApplied);
}

void UCharacterAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* abilitySystemComponent, const FGameplayEffectSpec& effectSpec, FActiveGameplayEffectHandle activeGameplayEffectHandle)
{
	FGameplayTagContainer gameplayTagContainer;
	effectSpec.GetAllAssetTags(gameplayTagContainer);
	effectAssetTagDelegate.Broadcast(gameplayTagContainer);
}
