// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PixelShaderUsageExample.h"
#include "UnrealProjectShadedSphere.generated.h"

UCLASS()
class UNREALPROJECT_API AUnrealProjectShadedSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnrealProjectShadedSphere();
	AUnrealProjectShadedSphere(const FObjectInitializer& objectInitializer);


	virtual void BeginPlay() override; // Called when the game starts or when spawned 
	virtual void BeginDestroy() override; // Called when the game ends 
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
		UMaterialInterface* MaterialApplied; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
		UTextureRenderTarget2D* RenderTarget; 

private : 
	FPixelShaderUsageExample* PixelShading;
	UStaticMeshComponent* m_sphereVisual;

	void SavePixelShaderOutput(); 
	
};
