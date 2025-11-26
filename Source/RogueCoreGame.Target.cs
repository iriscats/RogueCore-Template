using UnrealBuildTool;

public class RogueCoreGameTarget : TargetRules {
	public RogueCoreGameTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;

		// UE 5.6 Default Build Settings
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		CppStandard = CppStandardVersion.Cpp20;
        bUseUnityBuild = false;

        // Disable FormatStringSanitizer in UE 5.6 to avoid compilation errors
        AdditionalCompilerArguments = "-d2-fmt+";

		ExtraModuleNames.AddRange(new string[] {
			"RogueCore",
			"RogueCoreEngine",
		});
	}
}
