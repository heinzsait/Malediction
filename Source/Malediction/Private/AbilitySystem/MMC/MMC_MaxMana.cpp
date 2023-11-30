// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"

#include "AbilitySystem/CharacterAttributeSet.h"
#include "Interfaces/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	intelligenceDefinition.AttributeToCapture = UCharacterAttributeSet::GetIntelligenceAttribute();
	intelligenceDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	intelligenceDefinition.bSnapshot = false;

	RelevantAttributesToCapture.Add(intelligenceDefinition);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* source = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* target = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = source;
	EvaluateParameters.TargetTags = target;

	float intelligenceMagnitude = 0.0f;	
	GetCapturedAttributeMagnitude(intelligenceDefinition, Spec, EvaluateParameters, intelligenceMagnitude);

	intelligenceMagnitude = FMath::Max(intelligenceMagnitude, 0.0f);

	int32 playerLvl = 0;
	if(ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()))
	{
		playerLvl = CombatInterface->GetPlayerLevel();
	}

	return (80 + 2 * intelligenceMagnitude + 10 * playerLvl);	
}
