

#include "SimpleMaterialPrivatePCH.h"

ASimpleSphere::ASimpleSphere(const FObjectInitializer& objectInitializer): 
	Super(objectInitializer),
	m_sphere(nullptr)
{
	UE_LOG(LogTemp, Warning, TEXT("Im a sphere!"));

	// We need a scene component to represent the sphere
	USphereComponent* SceneComponent = objectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->Mobility = EComponentMobility::Static;

	// Create and position a mesh component so we can see our sphere in the world
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->AttachTo(RootComponent);

	UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, 
		TEXT("/Game/StarterContent/Shapes/Shape_Sphere")));

	if (meshToUse)
	{
		UE_LOG(LogTemp, Warning, TEXT("Mesh found!"));
		SphereVisual->SetStaticMesh(meshToUse);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	//assign material to mesh
	UMaterial* material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL,
		TEXT("/Game/StarterContent/materials/M_Metal_Gold")));

	if (material)
	{
		UE_LOG(LogTemp, Warning, TEXT("Material found!"));
		SphereVisual->SetMaterial(0, material);
	}


}
