// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/CharacterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	if (UCharacterAttributeSet* characterAttributeSet = Cast<UCharacterAttributeSet>(attributeSet))
	{
		OnHealthChanged.Broadcast(characterAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(characterAttributeSet->GetMaxHealth());
		OnManaChanged.Broadcast(characterAttributeSet->GetMana());
		OnMaxManaChanged.Broadcast(characterAttributeSet->GetMaxMana());
	}
}

void UOverlayWidgetController::BindCallbacks()
{
	if (UCharacterAttributeSet* characterAttributeSet = Cast<UCharacterAttributeSet>(attributeSet))
	{
		abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(characterAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
		abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(characterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
		abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(characterAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
		abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(characterAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	}
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}