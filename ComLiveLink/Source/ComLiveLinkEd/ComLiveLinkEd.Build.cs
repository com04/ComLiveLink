// Copyright com04. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ComLiveLinkEd : ModuleRules
{
	public ComLiveLinkEd(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"ComLiveLinkEd/Private",
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
				"AnimGraph",
				"BlueprintGraph",
				"ComLiveLink",
				"CoreUObject",
				"Engine",
				"Projects",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);
	}
}
