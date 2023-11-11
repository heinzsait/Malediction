// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;

	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weaponMesh->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
