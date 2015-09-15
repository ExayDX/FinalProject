// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "UnrealProjectShadedSphere.h"


// Sets default values
AUnrealProjectShadedSphere::AUnrealProjectShadedSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TArray<UStaticMeshComponent*> ActorComponents = TArray<UStaticMeshComponent*>();	
	GetComponents<UStaticMeshComponent>(ActorComponents);
	
	for (int32 i = 0; i < ActorComponents.Num(); ++i)
	{
		UStaticMeshComponent* CurrentComponent = ActorComponents[i];
		CurrentComponent->SetMaterial(0, MaterialApplied);
		UMaterialInstanceDynamic* MID = CurrentComponent->CreateAndSetMaterialInstanceDynamic(0);
		UTexture* CastedrenderTarget = Cast<UTexture>(RenderTarget); 
		MID->SetTextureParameterValue("InputTexture", CastedrenderTarget); 
	}

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
	}


}

void AUnrealProjectShadedSphere::SavePixelShaderOutput()
{
	PixelShading->Save(); 
}