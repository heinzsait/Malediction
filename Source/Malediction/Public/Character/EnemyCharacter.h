// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interfaces/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MALEDICTION_API AEnemyCharacter : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
public:

	AEnemyCharacter();
	virtual void BeginPlay() override;
	
protected:

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	virtual void InitAbilitySystemAndAttribute() override;

private:

	bool highlighted = false;
};
