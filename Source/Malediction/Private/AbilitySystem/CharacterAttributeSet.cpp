// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include <AbilitySystemGlobals.h>


UCharacterAttributeSet::UCharacterAttributeSet()
{
	//InitHealth(50);
	//InitMana(50);
}

void UCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Mana, COND_None, REPNOTIFY_Always);

	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Strength, COND_None, REPNOTIFY_Always);	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Resilience, COND_None, REPNOTIFY_Always);	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Vigor, COND_None, REPNOTIFY_Always);

	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, CriticalHitResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always);	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}


void UCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties effectProperties;
	SetEffectProperties(Data, effectProperties);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
	
}


void UCharacterAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& effectProperties)
{
	
	effectProperties.effectContextHandle = Data.EffectSpec.GetContext();
	effectProperties.sourceASC = effectProperties.effectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(effectProperties.sourceASC) && effectProperties.sourceASC->AbilityActorInfo.IsValid() && effectProperties.sourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		effectProperties.sourceAvatarActor = effectProperties.sourceASC->AbilityActorInfo->AvatarActor.Get();
		effectProperties.sourceController = effectProperties.sourceASC->AbilityActorInfo->PlayerController.Get();
		if (effectProperties.sourceController == nullptr && effectProperties.sourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(effectProperties.sourceAvatarActor))
				effectProperties.sourceController = Pawn->GetController();
		}
		if (effectProperties.sourceController)
			ACharacter* SourceCharacter = Cast<ACharacter>(effectProperties.sourceController->GetPawn());
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		effectProperties.targetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		effectProperties.targetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		effectProperties.targetCharacter = Cast<ACharacter>(effectProperties.targetAvatarActor);
		effectProperties.targetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(effectProperties.targetAvatarActor);
	}
	
}


void UCharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& oldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Health, oldHealth);
}

void UCharacterAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, MaxHealth, oldMaxHealth);
}

void UCharacterAttributeSet::OnRep_Mana(const FGameplayAttributeData& oldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Mana, oldMana);
}

void UCharacterAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, MaxMana, oldMaxMana);
}

void UCharacterAttributeSet::OnRep_Strength(const FGameplayAttributeData& oldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Strength, oldStrength);
}

void UCharacterAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& oldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Intelligence, oldIntelligence);
}

void UCharacterAttributeSet::OnRep_Resilience(const FGameplayAttributeData& oldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Resilience, oldResilience);
}

void UCharacterAttributeSet::OnRep_Vigor(const FGameplayAttributeData& oldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Vigor, oldVigor);
}

void UCharacterAttributeSet::OnRep_Armor(const FGameplayAttributeData& oldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Armor, oldArmor);
}

void UCharacterAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& oldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, ArmorPenetration, oldArmorPenetration);
}

void UCharacterAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& oldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, BlockChance, oldBlockChance);
}

void UCharacterAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& oldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, CriticalHitChance, oldCriticalHitChance);
}

void UCharacterAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& oldCriticalHitDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, CriticalHitDamage, oldCriticalHitDamage);
}

void UCharacterAttributeSet::OnRep_CriticalHitResistance(const FGameplayAttributeData& oldCriticalHitResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, CriticalHitResistance, oldCriticalHitResistance);
}

void UCharacterAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& oldHealthRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, HealthRegeneration, oldHealthRegeneration);
}

void UCharacterAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& oldManaRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, ManaRegeneration, oldManaRegeneration);
}

