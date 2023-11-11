// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class MALEDICTION_API UWidgetController : public UObject
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerController> playerController;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerState> playerState;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> attributeSet;

};
