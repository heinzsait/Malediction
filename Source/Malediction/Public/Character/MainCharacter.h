// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MALEDICTION_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
	
	virtual int32 GetPlayerLevel() override;

protected:


	virtual void InitAbilitySystemAndAttribute() override;
	

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};
