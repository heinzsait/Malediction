// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyAnimInstance.h"
#include "Character/EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
	character = Cast<AEnemyCharacter>(GetOwningActor());
	if (character)
	{
		characterMovement = character->GetCharacterMovement();
	}
}

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (character && characterMovement)
	{
		groundSpeed = UKismetMathLibrary::VSizeXY(characterMovement->Velocity);
	}
}
