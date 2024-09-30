// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cyprus_365 : ModuleRules
{
	public Cyprus_365(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput","ApplicationCore" });
	}
}
