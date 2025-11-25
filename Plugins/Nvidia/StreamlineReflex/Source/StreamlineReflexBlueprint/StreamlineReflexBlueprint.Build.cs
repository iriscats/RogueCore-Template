using UnrealBuildTool;

public class StreamlineReflexBlueprint : ModuleRules {
    public StreamlineReflexBlueprint(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        // ShadowVariableWarningLevel deprecated in UE 5.6 - use new API below
        CppCompileWarningSettings.ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "StreamlineBlueprint",
        });
    }
}
