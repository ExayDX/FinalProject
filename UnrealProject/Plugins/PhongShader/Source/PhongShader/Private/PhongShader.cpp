// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "PhongShaderPrivatePCH.h"
#include "IPhongShader.h"


class FPhongShader : public IFPhongShader
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


};

IMPLEMENT_MODULE(FPhongShader, PhongShader)


void FPhongShader::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	//for (TObjectIterator<UObject> Itr; Itr; ++Itr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT(Itr->GetName())); 
	//}
	//PixelShader = new FPixelShaderUsageExample(PixelShaderTopLeftColor, GetWorld()->Scene->GetFeatureLevel());
}


void FPhongShader::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



