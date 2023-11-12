// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/WidgetController.h"

void UWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& params)
{
	playerController = params.playerController;
	playerState = params.playerState;
	abilitySystemComponent = params.abilitySystemComponent;
	attributeSet = params.attributeSet;
}

void UWidgetController::BroadcastInitialValues()
{

}

void UWidgetController::BindCallbacks()
{

}
