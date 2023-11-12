// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"
#include "UI/Widget/BaseUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AMainHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	check(overlayWidgetClass);
	check(overlayWidgetControllerClass);

	//UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), overlayWidgetClass);
	overlayWidget = CreateWidget<UBaseUserWidget>(GetWorld(), overlayWidgetClass);//Cast<UBaseUserWidget>(widget);

	const FWidgetControllerParams params(PC, PS, ASC, AS);

	UOverlayWidgetController* _overlayWidgetController = GetOverlayWidgetController(params);

	if(_overlayWidgetController)
		overlayWidget->SetWidgetController(_overlayWidgetController);

	overlayWidgetController->BroadcastInitialValues();	
	overlayWidget->AddToViewport();
}

UOverlayWidgetController* AMainHUD::GetOverlayWidgetController(const FWidgetControllerParams& params)
{
	if (overlayWidgetController == nullptr)
	{
		overlayWidgetController = NewObject<UOverlayWidgetController>(this, overlayWidgetControllerClass);
		overlayWidgetController->SetWidgetControllerParams(params);
		overlayWidgetController->BindCallbacks();
	}
	
	return overlayWidgetController;
}
