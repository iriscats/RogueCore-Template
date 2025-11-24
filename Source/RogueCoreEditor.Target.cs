using UnrealBuildTool;

public class RogueCoreEditorTarget : TargetRules {
	public RogueCoreEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;

		// UE 5.6 Default Build Settings
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		CppStandard = CppStandardVersion.Cpp20;
		// Note: BuildEnvironment.Unique cannot be used with installed engine
		// Will use default BuildEnvironment

		ExtraModuleNames.AddRange(new string[] {
			"RogueCore",
			"RogueCoreEngine",
		});
	}
}
