// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerState/MainPlayerState.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "UI/HUD/MainHUD.h"


AMainCharacter::AMainCharacter()
{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	SetAbilitySystemAndAttribute();
}

void AMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	SetAbilitySystemAndAttribute();
}

void AMainCharacter::SetAbilitySystemAndAttribute()
{
	if (AMainPlayerState* playerState = GetPlayerState<AMainPlayerState>())
	{
		playerState->GetAbilitySystemComponent()->InitAbilityActorInfo(playerState, this);
		abilitySystemComponent = playerState->GetAbilitySystemComponent();
		attributeSet = playerState->GetAttributeSet();

		APlayerController* playerController = Cast<APlayerController>(GetController());
		if (playerController)
		{
			if (AMainHUD* HUD = Cast<AMainHUD>(playerController->GetHUD()))
			{
				HUD->InitOverlay(playerController, playerState, abilitySystemComponent, attributeSet);
			}
		}
	}
}
