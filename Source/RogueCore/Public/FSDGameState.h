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

UCLASS(Blueprintable)
class ROGUECORE_API AFSDGameState : public AGameState {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNamedCountdownDelegate, const FNamedCountdownInt&, Countdown);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32DelegateEvent OnMissionTimeUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnMatchStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnMatchEnded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerDelegate OnPlayerJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerDelegate OnPlayerLeave;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnAllDwarvesDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyKilledDelegate OnEnemyKilledEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCharacterDelegate OnPlayerCharacterRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnNextWaveLevelTimeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnHostilePressureChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnActiveWaveTypesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnIsWaveActiveChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatDelegate OnLevelLifeTimeUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnInvalidatePositioningAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ATeamTransport* EscapePod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FSDSessionID, meta=(AllowPrivateAccess=true))
    FString FSDSessionID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoscoReviveCounterChanged OnBoscoReviveCounterChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTeamDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnTeamDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectivesDelegate OnObjectiveAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDifficultyDelegate OnDifficultyChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCountDownStarted OnCountdownStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCountdown OnCountdownTimeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnCountdownFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADeepCSGWorld* CSGWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastSupplyPodTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastCleaningPodTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AProceduralSetup* ProceduralSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DelayLateJoin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* FakeMovementBase;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatDelegate OnLevelTimeDilationChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAbilityUsageBlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAbilityUsageUnblocked;
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> RoundEndBlockers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsAbilityUsageBlocked, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AbilityUsageBlockers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResourceAmountPenalty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LossXPPenalty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextMissionCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextSecondaryObjective;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextSurvivalBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextMined;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextCollected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TextBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LastLeveLifeTime, meta=(AllowPrivateAccess=true))
    float LastLeveLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LevelTimeDilation, meta=(AllowPrivateAccess=true))
    float LevelTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_BoscoReviveCounter, meta=(AllowPrivateAccess=true))
    int32 BoscoReviveCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpawnEffectsComponent* SpawnEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicMeshScaler* MeshScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGemProximityTracker* GemProximityTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAttackerManagerComponent* AttackerManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDifficultyManager* DifficultyManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDifficultyController* DifficultyControllerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USoundMixManagerComponent* SoundMixManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USeasonReplicatorComponent* SeasonReplicatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBXEGameStateComponent* BXEStateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTeamResourcesComponent* TeamResources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsOnSpaceRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInMidstation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayerMadeItToDropPod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActivePlayerCharacters, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> ActivePlayerCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RememberDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerProximityTracker* ProximityTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShowroomManager* ShowroomManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGameStats* GameStats;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_MissionTime, meta=(AllowPrivateAccess=true))
    uint32 MissionTime;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 MissionStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool PreventLatejoinCharacterDuplication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CountdownRemaining, meta=(AllowPrivateAccess=true))
    int32 CountdownRemaining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CountdownText, meta=(AllowPrivateAccess=true))
    FText CountdownText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanCarryOverResources;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurrentLeaderChanged SessionLeaderChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerState* CurrentPlayerSessionLeader;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNamedCountdownDelegate OnNamedCountdownChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepEndLevelState, meta=(AllowPrivateAccess=true))
    FPlayerControllerLevelEndState LevelEndState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepNamedCountdowns, meta=(AllowPrivateAccess=true))
    TArray<FNamedCountdownInt> NamedCountdowns;
    
public:
    AFSDGameState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void WaitForInitialGenerationDone(AFSDGameState* GameState, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UnblockAbilityUsage(AActor* blocker);
    
    UFUNCTION(BlueprintCallable)
    void StartCountdown(int32 Duration, const FText& countdownName);
    
    UFUNCTION(BlueprintCallable)
    void SetPreventLatejoinCharacterDuplication(bool prevent);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayersHaveReachedDroppod(bool newHasPlayerReached);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetLevelTimeDilation(float newTimeDilation);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentDifficulty(UDifficultySetting* Setting, bool updateSessionSettings);
    

    UFUNCTION(BlueprintCallable)
    void ReplicateLeveLifeTime(AFSDPlayerState* InPlayerState);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveRoundEndBlocker(UObject* blocker);
    
    UFUNCTION(BlueprintCallable)
    void PostLocalizedGameMessage(const FText& Msg, const TArray<FText>& Arguments);
    
    UFUNCTION(BlueprintCallable)
    void PostGameMessage(const FString& Msg);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRepNamedCountdowns(const TArray<FNamedCountdownInt>& PreviousCountdowns);
    
    UFUNCTION(BlueprintCallable)
    void OnRepEndLevelState();
    

    UFUNCTION(BlueprintCallable)
    void OnRep_NextWaveLevelTime();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MissionTime();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_LevelTimeDilation();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_LastLeveLifeTime();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsWaveActive();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsAbilityUsageBlocked(TArray<AActor*> oldBlockers);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_HostilePressure();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_FSDSessionID();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentDifficultySetting();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CountdownText();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CountdownRemaining(int32 prevTime);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_BoscoReviveCounter();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActiveWaveTypes();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActivePlayerCharacters();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAbilityBlockerFreed(AActor* DestroyedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialMission() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRoundEndBlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCountingDown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilityUsageBlocked() const;
    
    UFUNCTION(BlueprintCallable)
    void InitObjectives();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void HostDisbandedTeam();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveStageSuccess() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveStageFailure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveRunSuccess() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveRunFailure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveRunAbort() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveReplicatedEndOfRunState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 HaveActiveWave() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasObjectivesReplicated() const;
    

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSeamlessTravelEvent();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFSDPlayerState* GetServerPlayerState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UObjective*> GetSecondaryObjectives() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AProceduralSetup* GetProceduralSetup();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObjective* GetPrimaryObjective() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreventLatejoinCharacterDuplication() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayersHaveReachedDroppod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<UPlayerCharacterID*> GetPlayableCharacterIDs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UObjective*> GetObjectives() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNextWaveLevelTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AFSDPlayerState*> GetNetworkSortedPlayerArray();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMissionTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMissionStartTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelTimeDilation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelLifeTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHostilePressure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGameStats* GetGameStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<UResourceData*, float> GetEndscreenResources() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDifficultyManager* GetDifficultyManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDifficultyController* GetDifficultyController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<UResourceData*, float> GetCollectedResources() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EWaveControllerType> GetActiveWaveTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UFSDEvent*> GetActiveEventsFromMission() const;
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void ClientNewMessage(const FFSDChatMessage& Msg);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Client_NewLocalizedMessage(const FFSDLocalizedChatMessage& Msg);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void BroadcastDepositedResource(APlayerCharacter* PlayerThatDeposited, UResourceData* DepositedResource, const float DepositedAmount);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void BlockAbilityUsage(AActor* blocker);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SpawnScaledEffectAt(FScaledEffect Effect, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SpawnScaledEffectAndCueAt(FScaledEffect Effect, USoundCue* Audio, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_ServerQuit();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, NetMulticast, Reliable)
    void All_InvalidateMovementAbilities();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddRoundEndBlocker(UObject* blocker);
    
};

