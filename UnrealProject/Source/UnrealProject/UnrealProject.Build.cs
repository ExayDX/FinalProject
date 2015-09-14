// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UnrealProject : ModuleRules
{
	public UnrealProject(TargetInfo Target)
	{
        PrivateIncludePaths.AddRange(new string[] { "UnrealProject/Private" });
		PublicDependencyModuleNames.AddRange(new string[]
        { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore",
            "RHI", 
            "PixelShader"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
        DynamicallyLoadedModuleNames.AddRange(new string[] {  });
        PrivateIncludePathModuleNames.AddRange(new string[] {  });

        if(UEBuildConfiguration.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.Add("UnrealEd"); 
        }



		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
