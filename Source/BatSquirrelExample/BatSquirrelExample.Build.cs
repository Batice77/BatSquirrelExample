// Copyright 2020 - Florent WASSEN

using UnrealBuildTool;

public class BatSquirrelExample : ModuleRules
{
	public BatSquirrelExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HTTP" });

		PrivateDependencyModuleNames.AddRange(new string[] {"Slate", "SlateCore", "UMG"});

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
