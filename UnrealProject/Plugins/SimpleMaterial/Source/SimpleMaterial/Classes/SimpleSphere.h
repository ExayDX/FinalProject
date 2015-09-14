

#pragma once

#include "SimpleSphere.generated.h"

//Simple sphere


UCLASS(ClassGroup = SimpleMaterial, Blueprintable, BlueprintType)
class ASimpleSphere: public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	float MyStruct;

	USphereComponent* m_sphere;
public:

	bool getText() { return true; }
};