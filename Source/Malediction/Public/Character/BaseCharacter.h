// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/CombatInterface.h"
#include "BaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS()
class MALEDICTION_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:

	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return attributeSet; }

	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh() const { return weaponMesh; }


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> weaponMesh;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;

	
	virtual void InitAbilitySystemAndAttribute();
	
	void ApplyEffect(TSubclassOf<UGameplayEffect> effectClass, float level) const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> defaultPrimaryAttributes;

	void InitializePrimaryAttributes() const;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> defaultSecondaryAttributes;
	
	void InitializeSecondaryAttributes() const;
	void InitializeLifeAttributes() const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> defaultLifeAttributes;

private:

};
