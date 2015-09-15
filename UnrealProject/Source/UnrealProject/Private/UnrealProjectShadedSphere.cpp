// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "UnrealProjectShadedSphere.h"

#include <assert.h>

// Sets default values
AUnrealProjectShadedSphere::AUnrealProjectShadedSphere()
{}

AUnrealProjectShadedSphere::AUnrealProjectShadedSphere(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Im a sphere!"));

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and position a mesh component so we can see our sphere in the world
	m_sphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	m_sphereVisual->AttachTo(RootComponent);

	
	UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL,
		TEXT("/Game/StarterContent/Shapes/Shape_Sphere")));

	if (meshToUse)
	{
		UE_LOG(LogTemp, Warning, TEXT("Mesh found!"));
		m_sphereVisual->SetStaticMesh(meshToUse);
		m_sphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		m_sphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	//assign material to mesh
	UMaterial* material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL,
		TEXT("/Game/StarterContent/materials/M_Metal_Gold")));

	if (material)
	{
		UE_LOG(LogTemp, Warning, TEXT("Material found!"));
		m_sphereVisual->SetMaterial(0, material);
	}

	//enable ticking
	PrimaryActorTick.bCanEverTick = true;

	RenderTarget = NULL;

}

// Called when the game starts or when spawned
void AUnrealProjectShadedSphere::BeginPlay()
{
	Super::BeginPlay();
	PixelShading = new FPixelShaderUsageExample(FColor::Green, GetWorld()->Scene->GetFeatureLevel()); 
}

void AUnrealProjectShadedSphere::BeginDestroy()
{
	Super::BeginDestroy();

	if (PixelShading != nullptr)
	{
		delete PixelShading;
		PixelShading = nullptr; 
	}
}

// Called every frame
void AUnrealProjectShadedSphere::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (PixelShading != nullptr)
	{
		PixelShading->ExecutePixelShader(RenderTarget, nullptr, FColor(255, 0, 0, 255), 0);
		FString texName("myTexture");

		//make texture from render target
		UTexture* tex = Cast<UTexture>(RenderTarget);
		assert(tex);

		//assign texture to sphere
		UMaterialInstanceDynamic* MID = m_sphereVisual->CreateAndSetMaterialInstanceDynamic(0);
		MID->SetTextureParameterValue("InputTexture", tex);
	}


}

void AUnrealProjectShadedSphere::SavePixelShaderOutput()
{
	PixelShading->Save(); 
}