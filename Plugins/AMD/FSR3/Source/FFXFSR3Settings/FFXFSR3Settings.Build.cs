using UnrealBuildTool;

public class FFXFSR3Settings : ModuleRules {
    public FFXFSR3Settings(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        // ShadowVariableWarningLevel deprecated in UE 5.6 - use new API below
        CppCompileWarningSettings.ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
        });
    }
}
