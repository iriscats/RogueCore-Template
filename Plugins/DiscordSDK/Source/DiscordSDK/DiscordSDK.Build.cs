using UnrealBuildTool;

public class DiscordSDK : ModuleRules {
    public DiscordSDK(ReadOnlyTargetRules Target) : base(Target) {
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs; // UE 5.6 default
        // bLegacyPublicIncludePaths = false; // UE 5.6 default
        // ShadowVariableWarningLevel = WarningLevel.Warning; // UE 5.6 default
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
