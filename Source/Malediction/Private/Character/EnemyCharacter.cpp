// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

AEnemyCharacter::AEnemyCharacter()
{	
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	GetMesh()->SetCustomDepthStencilValue(250);

	GetWeaponMesh()->SetCustomDepthStencilValue(250);

	abilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(FName("Character Ability System Component"));
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	attributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(FName("Character Attribute Set"));
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemAndAttribute();
}

int32 AEnemyCharacter::GetPlayerLevel()
{
	return level;
}

void AEnemyCharacter::HighlightActor()
{
	highlighted = true;
	GetMesh()->SetRenderCustomDepth(highlighted);
	GetWeaponMesh()->SetRenderCustomDepth(highlighted);
}

void AEnemyCharacter::UnHighlightActor()
{
	highlighted = false;
	GetMesh()->SetRenderCustomDepth(highlighted);
	GetWeaponMesh()->SetRenderCustomDepth(highlighted);
}

void AEnemyCharacter::InitAbilitySystemAndAttribute()
{	
	if (abilitySystemComponent)
	{
		abilitySystemComponent->InitAbilityActorInfo(this, this);
		if(UCharacterAbilitySystemComponent* charASC = Cast<UCharacterAbilitySystemComponent>(abilitySystemComponent))
			charASC->ActorASCSet();
				
	}
}

