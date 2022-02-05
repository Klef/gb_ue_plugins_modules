
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class gb_modules : ModuleRules
{
	public gb_modules(ReadOnlyTargetRules Target) : base(Target)
	{

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"MediaAssets",
			"Slate",
			"SlateCore", 
			"DesktopPlatform",
			"UMG", 
			"MediaAssets", 
		});
		 PrivateDependencyModuleNames.AddRange(new string[]
		 {
			"InventorySystem",
		 });
	}
}
