using UnrealBuildTool;

public class BasicUI : ModuleRules {
    public BasicUI(ReadOnlyTargetRules Target) : base(Target) {
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs; // UE 5.6 default
        // bLegacyPublicIncludePaths = false; // UE 5.6 default
        // ShadowVariableWarningLevel = WarningLevel.Warning; // UE 5.6 default
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}
