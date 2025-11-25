#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Engine/LatentActionManager.h"
#include "Engine/NetSerialization.h"
#include "BoolDelegateDelegate.h"
#include "BoscoReviveCounterChangedDelegate.h"
#include "CountDownStartedDelegate.h"
#include "CountdownDelegate.h"
#include "CurrentLeaderChangedDelegate.h"
#include "DelegateDelegate.h"
#include "DelegateEventDelegate.h"
#include "DifficultyDelegateDelegate.h"
#include "EWaveControllerType.h"
#include "EnemyKilledDelegateDelegate.h"
#include "FSDChatMessage.h"
#include "FSDLocalizedChatMessage.h"
#include "FloatDelegateDelegate.h"
#include "Int32DelegateEventDelegate.h"
#include "NamedCountdownInt.h"
#include "ObjectivesDelegateDelegate.h"
#include "PlayerCharacterDelegateDelegate.h"
#include "PlayerControllerLevelEndState.h"
#include "PlayerDelegateDelegate.h"
#include "ReplicatedObjectives.h"
#include "ScaledEffect.h"
#include "FSDGameState.generated.h"

class AActor;
class ADeepCSGWorld;
class AFSDGameState;
class AFSDPlayerState;
class AGameStats;
class APlayerCharacter;
class APlayerState;
class AProceduralSetup;
class ATeamTransport;
class UAttackerManagerComponent;
class UBXEGameStateComponent;
class UDifficultyController;
class UDifficultyManager;
class UDifficultySetting;
class UDynamicMeshScaler;
class UFSDEvent;
class UGemProximityTracker;
class UObject;
class UObjective;
class UPlayerCharacterID;
class UPlayerProximityTracker;
class UPrimitiveComponent;
class UResourceData;
class USeasonReplicatorComponent;
class UShowroomManager;
class USoundCue;
class USoundMixManagerComponent;
class USpawnEffectsComponent;
class UTeamResourcesComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFSDGameState : public AGameState {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNamedCountdownDelegate, const FNamedCountdownInt&, Countdown);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32DelegateEvent OnMissionTimeUpdated;
    FDelegateEvent OnMatchStarted;
    FDelegateEvent OnMatchEnded;
    FPlayerDelegate OnPlayerJoined;
    FPlayerDelegate OnPlayerLeave;
    FDelegateEvent OnAllDwarvesDown;
    FEnemyKilledDelegate OnEnemyKilledEvent;
    FPlayerCharacterDelegate OnPlayerCharacterRegistered;
    FDelegateEvent OnNextWaveLevelTimeChanged;
    FDelegateEvent OnHostilePressureChanged;
    FDelegateEvent OnActiveWaveTypesChanged;
    FBoolDelegate OnIsWaveActiveChanged;
    FFloatDelegate OnLevelLifeTimeUpdated;
    FDelegate OnInvalidatePositioningAbilities;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ATeamTransport* EscapePod;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FSDSessionID, meta=(AllowPrivateAccess=true))
    FString FSDSessionID;
    FBoscoReviveCounterChanged OnBoscoReviveCounterChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTeamDown;
    FBoolDelegate OnTeamDown;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectivesDelegate OnObjectiveAdded;
    FDifficultyDelegate OnDifficultyChanged;
    FCountDownStarted OnCountdownStarted;
    FCountdown OnCountdownTimeChanged;
    FDelegateEvent OnCountdownFinished;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADeepCSGWorld* CSGWorld;
    int32 LastSupplyPodTimeStamp;
    int32 LastCleaningPodTimeStamp;
    AProceduralSetup* ProceduralSetup;
    bool DelayLateJoin;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* FakeMovementBase;
    FFloatDelegate OnLevelTimeDilationChanged;
    FDelegate OnAbilityUsageBlocked;
    FDelegate OnAbilityUsageUnblocked;

    TArray<UObject*> RoundEndBlockers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsAbilityUsageBlocked, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AbilityUsageBlockers;
    float ResourceAmountPenalty;
    float LossXPPenalty;
    FText TextMissionCompleted;
    FText TextSecondaryObjective;
    FText TextSurvivalBonus;
    FText TextMined;
    FText TextCollected;
    FText TextBonus;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LastLeveLifeTime, meta=(AllowPrivateAccess=true))
    float LastLeveLifeTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LevelTimeDilation, meta=(AllowPrivateAccess=true))
    float LevelTimeDilation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_BoscoReviveCounter, meta=(AllowPrivateAccess=true))
    int32 BoscoReviveCounter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpawnEffectsComponent* SpawnEffects;
    UDynamicMeshScaler* MeshScaler;
    UGemProximityTracker* GemProximityTracker;
    UAttackerManagerComponent* AttackerManager;
    UDifficultyManager* DifficultyManagerComponent;
    UDifficultyController* DifficultyControllerComponent;
    USoundMixManagerComponent* SoundMixManager;
    USeasonReplicatorComponent* SeasonReplicatorComponent;
    UBXEGameStateComponent* BXEStateComponent;
    UTeamResourcesComponent* TeamResources;
    bool IsOnSpaceRig;
    bool IsInMidstation;
    bool PlayerMadeItToDropPod;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActivePlayerCharacters, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> ActivePlayerCharacters;
    FReplicatedObjectives Objectives;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentDifficultySetting, meta=(AllowPrivateAccess=true))
    UDifficultySetting* CurrentDifficultySetting;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_NextWaveLevelTime, meta=(AllowPrivateAccess=true))
    float NextWaveLevelTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HostilePressure, meta=(AllowPrivateAccess=true))
    float HostilePressure;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ActiveWaveTypes, meta=(AllowPrivateAccess=true))
    TArray<EWaveControllerType> ActiveWaveTypes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsWaveActive, meta=(AllowPrivateAccess=true))
    bool IsWaveActive;
    bool RememberDifficulty;
    UPlayerProximityTracker* ProximityTracker;
    UShowroomManager* ShowroomManager;
    AGameStats* GameStats;
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_MissionTime, meta=(AllowPrivateAccess=true))
    uint32 MissionTime;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 MissionStartTime;
    bool PreventLatejoinCharacterDuplication;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CountdownRemaining, meta=(AllowPrivateAccess=true))
    int32 CountdownRemaining;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CountdownText, meta=(AllowPrivateAccess=true))
    FText CountdownText;
    bool CanCarryOverResources;
    FCurrentLeaderChanged SessionLeaderChanged;
    APlayerState* CurrentPlayerSessionLeader;
    FNamedCountdownDelegate OnNamedCountdownChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepEndLevelState, meta=(AllowPrivateAccess=true))
    FPlayerControllerLevelEndState LevelEndState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepNamedCountdowns, meta=(AllowPrivateAccess=true))
    TArray<FNamedCountdownInt> NamedCountdowns;
    AFSDGameState(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void WaitForInitialGenerationDone(AFSDGameState* GameState, FLatentActionInfo LatentInfo);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UnblockAbilityUsage(AActor* blocker);
    UFUNCTION(BlueprintCallable)
    void StartCountdown(int32 Duration, const FText& countdownName);
    void SetPreventLatejoinCharacterDuplication(bool prevent);
    void SetPlayersHaveReachedDroppod(bool newHasPlayerReached);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetLevelTimeDilation(float newTimeDilation);
    void SetCurrentDifficulty(UDifficultySetting* Setting, bool updateSessionSettings);
    void ReplicateLeveLifeTime(AFSDPlayerState* InPlayerState);
    void RemoveRoundEndBlocker(UObject* blocker);
    void PostLocalizedGameMessage(const FText& Msg, const TArray<FText>& Arguments);
    void PostGameMessage(const FString& Msg);
    UFUNCTION()
    void OnRepNamedCountdowns(const TArray<FNamedCountdownInt>& PreviousCountdowns);
    UFUNCTION()
    void OnRepEndLevelState();
    UFUNCTION()
    void OnRep_NextWaveLevelTime();
    UFUNCTION()
    void OnRep_MissionTime();
    UFUNCTION()
    void OnRep_LevelTimeDilation();
    UFUNCTION()
    void OnRep_LastLeveLifeTime();
    UFUNCTION()
    void OnRep_IsWaveActive();
    UFUNCTION()
    void OnRep_IsAbilityUsageBlocked(TArray<AActor*> oldBlockers);
    UFUNCTION()
    void OnRep_HostilePressure();
    UFUNCTION()
    void OnRep_FSDSessionID();
    UFUNCTION()
    void OnRep_CurrentDifficultySetting();
    UFUNCTION()
    void OnRep_CountdownText();
    UFUNCTION()
    void OnRep_CountdownRemaining(int32 prevTime);
    UFUNCTION()
    void OnRep_BoscoReviveCounter();
    UFUNCTION()
    void OnRep_ActiveWaveTypes();
    UFUNCTION()
    void OnRep_ActivePlayerCharacters();
    void OnAbilityBlockerFreed(AActor* DestroyedActor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialMission() const;
    bool IsRoundEndBlocked() const;
    bool IsCountingDown() const;
    bool IsAbilityUsageBlocked() const;
    void InitObjectives();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void HostDisbandedTeam();
    bool HaveStageSuccess() const;
    bool HaveStageFailure() const;
    bool HaveRunSuccess() const;
    bool HaveRunFailure() const;
    bool HaveRunAbort() const;
    bool HaveReplicatedEndOfRunState() const;
    int32 HaveActiveWave() const;
    bool HasObjectivesReplicated() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSeamlessTravelEvent();
    AFSDPlayerState* GetServerPlayerState();
    TArray<UObjective*> GetSecondaryObjectives() const;
    AProceduralSetup* GetProceduralSetup();
    UObjective* GetPrimaryObjective() const;
    bool GetPreventLatejoinCharacterDuplication() const;
    bool GetPlayersHaveReachedDroppod() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<UPlayerCharacterID*> GetPlayableCharacterIDs();
    TArray<UObjective*> GetObjectives() const;
    float GetNextWaveLevelTime() const;
    TArray<AFSDPlayerState*> GetNetworkSortedPlayerArray();
    int32 GetMissionTime() const;
    int32 GetMissionStartTime() const;
    float GetLevelTimeDilation() const;
    float GetLevelLifeTime() const;
    float GetHostilePressure() const;
    AGameStats* GetGameStats() const;
    TMap<UResourceData*, float> GetEndscreenResources() const;
    UDifficultyManager* GetDifficultyManager() const;
    UDifficultyController* GetDifficultyController() const;
    TMap<UResourceData*, float> GetCollectedResources() const;
    TArray<EWaveControllerType> GetActiveWaveTypes() const;
    TArray<UFSDEvent*> GetActiveEventsFromMission() const;
    UFUNCTION(Client, Reliable)
    void ClientNewMessage(const FFSDChatMessage& Msg);
    UFUNCTION(Client, Reliable)
    void Client_NewLocalizedMessage(const FFSDLocalizedChatMessage& Msg);
    UFUNCTION(Client, Reliable)
    void BroadcastDepositedResource(APlayerCharacter* PlayerThatDeposited, UResourceData* DepositedResource, const float DepositedAmount);
    void BlockAbilityUsage(AActor* blocker);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SpawnScaledEffectAt(FScaledEffect Effect, FVector_NetQuantize Location);
    UFUNCTION(NetMulticast, Unreliable)
    void All_SpawnScaledEffectAndCueAt(FScaledEffect Effect, USoundCue* Audio, FVector_NetQuantize Location);
    UFUNCTION(NetMulticast, Reliable)
    void All_ServerQuit();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, NetMulticast, Reliable)
    void All_InvalidateMovementAbilities();
    void AddRoundEndBlocker(UObject* blocker);
};
