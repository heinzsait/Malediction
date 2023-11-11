// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/CharacterAttributeSet.h"

AEffectActor::AEffectActor()
{
 	PrimaryActorTick.bCanEverTick = false;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(mesh);

	sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	sphere->SetupAttachment(GetRootComponent());
}

void AEffectActor::BeginPlay()
{
	Super::BeginPlay();

	sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnOverlap);
	sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActor::EndOverlap);
}

void AEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* interface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UCharacterAttributeSet* attributeSet = Cast<UCharacterAttributeSet>(interface->GetAbilitySystemComponent()->GetAttributeSet(UCharacterAttributeSet::StaticClass()));

		UCharacterAttributeSet* MutableAuraAttributeSet = const_cast<UCharacterAttributeSet*>(attributeSet);
		MutableAuraAttributeSet->SetHealth(attributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}