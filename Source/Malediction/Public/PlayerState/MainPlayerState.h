// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "MainPlayerState.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class MALEDICTION_API AMainPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AMainPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return attributeSet; }
	
protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;
};
