using UnrealBuildTool;

public class DLSSMoviePipelineSupport : ModuleRules {
    public DLSSMoviePipelineSupport(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        // ShadowVariableWarningLevel deprecated in UE 5.6 - use new API below
        CppCompileWarningSettings.ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "MovieRenderPipelineCore",
        });
    }
}
