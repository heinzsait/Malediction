// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxHealth.h"

#include "AbilitySystem/CharacterAttributeSet.h"
#include "Interfaces/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	vigorDefinition.AttributeToCapture = UCharacterAttributeSet::GetVigorAttribute();
	vigorDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	vigorDefinition.bSnapshot = false;

	RelevantAttributesToCapture.Add(vigorDefinition);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* source = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* target = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = source;
	EvaluateParameters.TargetTags = target;

	float vigorMagnitude = 0.0f;	
	GetCapturedAttributeMagnitude(vigorDefinition, Spec, EvaluateParameters, vigorMagnitude);

	vigorMagnitude = FMath::Max(vigorMagnitude, 0.0f);

	int32 playerLvl = 0;
	if(ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()))
	{
		playerLvl = CombatInterface->GetPlayerLevel();
	}

	return (70 + 2 * vigorMagnitude + 10 * playerLvl);	
}
