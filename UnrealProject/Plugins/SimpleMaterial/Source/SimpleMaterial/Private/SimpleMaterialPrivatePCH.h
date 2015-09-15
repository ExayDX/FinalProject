// Some copyright should be here...
#ifndef __SIMPLEMATERIALPCH_H__
#define __SIMPLEMATERIALPCH_H__


//Engine
#include "CoreUObject.h"
#include "GameFramework/Actor.h"

#include "Components/SphereComponent.h"
#include "Components/MeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

#include "Runtime/Engine/Public/MaterialCompiler.h" //needed to avoid compile errors when including "materials.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

#include "ShaderParameters.h"
#include "ShaderParameterUtils.h"
#include "GlobalShader.h"
#include "MaterialShader.h"

#include "ConstructorHelpers.h"

//Plugin
#include "SimpleMaterial.h"
#include "Classes/SimpleSphere.h"
#include "Classes/SimpleMaterialShader.h"


//Std lib
#include <assert.h>
#include <string>

#endif //__SIMPLEMATERIALPCH_H__