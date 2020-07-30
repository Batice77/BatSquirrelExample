// Copyright 2020 - Florent WASSEN

using UnrealBuildTool;
using System.Collections.Generic;

public class BatSquirrelExampleTarget : TargetRules
{
	public BatSquirrelExampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "BatSquirrelExample" } );
	}
}
