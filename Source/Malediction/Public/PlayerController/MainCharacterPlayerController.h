// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterPlayerController.generated.h"

class AMainCharacter;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UNiagaraSystem;

UCLASS()
class MALEDICTION_API AMainCharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMainCharacterPlayerController();	

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;

	// To add mapping context
	virtual void BeginPlay();

	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	void OnTouchTriggered();
	void OnTouchReleased();

	void Move(const FInputActionValue& InputActionValue);

private:
	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

	UPROPERTY()
	TObjectPtr <AMainCharacter> playerCharacter;

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, Category = Input)
	float ShortPressThreshold = 0.3f;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr <UNiagaraSystem> FXCursor;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UInputMappingContext> DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UInputAction> moveAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UInputAction> SetDestinationClickAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UInputAction> SetDestinationTouchAction;
};
