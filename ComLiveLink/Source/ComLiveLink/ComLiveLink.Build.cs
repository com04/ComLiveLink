// Copyright com04. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ComLiveLink : ModuleRules
{
	public ComLiveLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"ComLiveLink/Private",
			}
			);
		string EnginePath = Path.GetFullPath(Target.RelativeEnginePath);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"ApplicationCore",
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AnimGraphRuntime",
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"Json",
				"Networking",
				"Projects",
				"Sockets",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);
	}
}
