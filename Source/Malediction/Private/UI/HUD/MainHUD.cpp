// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"
#include "UI/Widget/BaseUserWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	widget->AddToViewport();
}
