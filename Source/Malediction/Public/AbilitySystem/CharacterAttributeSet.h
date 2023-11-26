// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	FGameplayEffectContextHandle effectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* sourceASC = nullptr;

	UPROPERTY()
	AActor* sourceAvatarActor = nullptr;

	UPROPERTY()
	AController* sourceController = nullptr;

	UPROPERTY()
	ACharacter* sourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* targetASC = nullptr;

	UPROPERTY()
	AActor* targetAvatarActor = nullptr;

	UPROPERTY()
	AController* targetController = nullptr;

	UPROPERTY()
	ACharacter* targetCharacter = nullptr;
};


UCLASS()
class MALEDICTION_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UCharacterAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& oldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxMana);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& oldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Strength);
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& oldStrength) const;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Intelligence);
	
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& oldIntelligence) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience)
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Resilience);
	
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& oldResilience) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor)
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Vigor);
	
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& oldVigor) const;


	//Secondary Stats...
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Armor);
	
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& oldArmor) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration)
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, ArmorPenetration);
	
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& oldArmorPenetration) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance)
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, BlockChance);
	
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& oldBlockChance) const;

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance)
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CriticalHitChance);
	
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& oldCriticalHitChance) const;

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage)
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CriticalHitDamage);
	
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& oldCriticalHitDamage) const;

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance)
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CriticalHitResistance);
	
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& oldCriticalHitResistance) const;

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration)
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, HealthRegeneration);
	
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& oldHealthRegeneration) const;

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration)
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, ManaRegeneration);
	
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& oldManaRegeneration) const;
	
private:
	static void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);

};
