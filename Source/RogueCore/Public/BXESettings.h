#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEMissionShouts.h"
#include "DeadPlayerPlacementSettings.h"
#include "EnhancementSettings.h"
#include "LoadingScreenInfo.h"
#include "NegotiationMenuSettings.h"
#include "ReadyUpMenuSettings.h"
#include "VoteMenuSettings.h"
#include "BXESettings.generated.h"

class ADebrisDataActor;
class ATeamTransport;
class AXPRewarder;
class UBXEMissionStatSettings;
class UBXEProgressionSettings;
class UBiome;
class UCurveFloat;
class UMutator;
class URewardTree;
class URiskVector;
class URunSettings;
class UStageNameBank;
class UTreasureSettings;
UCLASS(Blueprintable)
class UBXESettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEProgressionSettings* ProgressionSettings;
    
    UBXEMissionStatSettings* MissionStats;
    UTreasureSettings* BXETreasureSettings;
    URunSettings* RunSettings;
    URewardTree* RewardTree;
    FDeadPlayerPlacementSettings DeadPlayerPlacement;
    TArray<UMutator*> BaseMutators;
    TArray<URiskVector*> RiskVectors;
    FBXEMissionShouts MissionControlShouts;
    TArray<FLoadingScreenInfo> LoadingSequences_FirstStage;
    FLoadingScreenInfo LoadingSequence_ElevatorIntro;
    FLoadingScreenInfo LoadingSequence_ElevatorLoop;
    TArray<FLoadingScreenInfo> LoadingSequences_AfterFirstStage;
    FLoadingScreenInfo LoadingSequence_EndScreen;
    UStageNameBank* BXENameBank;
    FEnhancementSettings EnhancementSettings;
    bool ObjectivesAreRequired;
    FNegotiationMenuSettings NegotiationMenuSettings;
    FVoteMenuSettings VoteMenuSettings;
    FReadyUpMenuSettings ReadyUpSettings;
    int32 CreditsPerPrimaryObjective;
    int32 CreditsPerSecondaryObjective;
    int32 XPPerPrimaryObjective;
    int32 XPPerExpenite;
    float XPNiteValueMultiplier;
    float XPPerKill;
    int32 MaxReclaimerPointLevel;
    float XPToReclaimerPointsConversionRate;
    UCurveFloat* XPToReclaimerPointsCurve;
    float ReclaimerPointsToChipConversionRate;
    TArray<float> ReclaimerPointsPerChip;
    float SecurityCameraReclaimerPointsMultiplier;
    TSoftClassPtr<ATeamTransport> LastLevelEscapePodClass;
    TSoftClassPtr<ATeamTransport> FirstLevelDropPodClass;
    TSoftClassPtr<AXPRewarder> XPRewarderClass;
    TSoftClassPtr<ADebrisDataActor> ExtraBXEDebris;
    TArray<UBiome*> NormalBiomes;
    UBiome* DeepCoreBiome;
    UBXESettings();
};
