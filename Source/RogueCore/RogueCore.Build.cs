using UnrealBuildTool;

public class RogueCore : ModuleRules {
    public RogueCore(ReadOnlyTargetRules Target) : base(Target) {
        // UE 5.6+ build settings
        DefaultBuildSettings = BuildSettingsVersion.V5;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AnimGraphRuntime",
            "AnimationSharing",
            "AudioMixer",
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
            "NetCore",
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
