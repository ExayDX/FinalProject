

#include "SimpleMaterialPrivatePCH.h"

ASimpleSphere::ASimpleSphere(const FObjectInitializer& objectInitializer): 
	Super(objectInitializer),
	m_sphere(nullptr)
{
	UE_LOG(LogTemp, Warning, TEXT("Im a sphere!"));

	// We need a scene component to
	USphereComponent* SceneComponent = objectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->Mobility = EComponentMobility::Static;

}
