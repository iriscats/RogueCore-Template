using UnrealBuildTool;

public class RogueCoreEngine : ModuleRules {
    public RogueCoreEngine(ReadOnlyTargetRules Target) : base(Target) {
        // UE 5.6 uses DefaultBuildSettings.V5, which sets these by default
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        // bLegacyPublicIncludePaths = false;
        // ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "PhysicsCore",
        });
    }
}
