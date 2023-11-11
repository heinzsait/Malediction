// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MALEDICTION_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<class AEnemyCharacter> character;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<class UCharacterMovementComponent> characterMovement;

	UPROPERTY(BlueprintReadWrite)
	float groundSpeed;
};
