// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/BaseUserWidget.h"

void UBaseUserWidget::SetWidgetController(UObject* _widgetController)
{
	widgetController = _widgetController;
	WidgetControllerSet();
}
