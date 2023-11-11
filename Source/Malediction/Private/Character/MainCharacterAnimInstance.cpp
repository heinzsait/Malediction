// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacterAnimInstance.h"
#include "Character/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMainCharacterAnimInstance::NativeInitializeAnimation()
{
	character = Cast<AMainCharacter>(GetOwningActor());
	if (character)
	{
		characterMovement = character->GetCharacterMovement();
	}
}

void UMainCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (character && characterMovement)
	{
		groundSpeed = UKismetMathLibrary::VSizeXY(characterMovement->Velocity);
	}
}
