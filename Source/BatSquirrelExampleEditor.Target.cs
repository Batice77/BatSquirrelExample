// Copyright 2020 - Florent WASSEN

using UnrealBuildTool;
using System.Collections.Generic;

public class BatSquirrelExampleEditorTarget : TargetRules
{
	public BatSquirrelExampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "BatSquirrelExample" } );
	}
}
