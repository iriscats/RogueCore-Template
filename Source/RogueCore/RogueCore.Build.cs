using UnrealBuildTool;

public class RogueCore : ModuleRules {
    public RogueCore(ReadOnlyTargetRules Target) : base(Target) {
        // UE 5.6 uses DefaultBuildSettings.V5, which sets these by default
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        // bLegacyPublicIncludePaths = false;
        // ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AnimGraphRuntime",
            "AnimationSharing",
            "BasicUI",
            "Core",
            "CoreUObject",
            "DLSSBlueprint",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "InputCore",
            "LevelSequence",
            "MediaAssets",
            "MetasoundEngine",
            "MovieScene",
            "Niagara",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "PhysicsCore",
            "RogueCoreEngine",
            "Slate",
            "SlateCore",
            "TemplateSequence",
            "UMG",
        });
    }
}
