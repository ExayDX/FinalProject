// Some copyright should be here...

#include "SimpleMaterialPrivatePCH.h"



#define LOCTEXT_NAMESPACE "FSimpleMaterialModule"

void FSimpleMaterialModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("Starting SimpleMaterial plugin"));
	
	//spawn simple sphere
	//USimpleSphere sphere;
	//sphere.getText();
	//assert(sphere.getText());
}

void FSimpleMaterialModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogTemp, Warning, TEXT("Shutting down SimpleMaterial plugin"));
	
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSimpleMaterialModule, SimpleMaterial)