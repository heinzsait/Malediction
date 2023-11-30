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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return attributeSet; }

	FORCEINLINE int32 GetPlayerLevel() const { return level; }
	
protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;

private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 level = 1;
	
	UFUNCTION()
	void OnRep_Level(int32 oldLevel);
};
