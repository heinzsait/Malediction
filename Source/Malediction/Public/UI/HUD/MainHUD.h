// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

class UBaseUserWidget;

UCLASS()
class MALEDICTION_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UBaseUserWidget>  OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBaseUserWidget> OverlayWidgetClass;
};
