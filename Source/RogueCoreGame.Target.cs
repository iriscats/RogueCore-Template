using UnrealBuildTool;

public class RogueCoreGameTarget : TargetRules {
	public RogueCoreGameTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;

		// UE 5.6 Default Build Settings
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		CppStandard = CppStandardVersion.Cpp20;
        bUseUnityBuild = false;

        // Override build environment to avoid conflicts
        bOverrideBuildEnvironment = true;

		ExtraModuleNames.AddRange(new string[] {
			"RogueCore",
			"RogueCoreEngine",
		});
	}
}
