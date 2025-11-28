#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "DelegateDelegate.h"
#include "EEnemyHealthScaling.h"
#include "EMissionShoutID.h"
#include "IntDelegateDelegate.h"
#include "RunCreationParameters.h"
#include "RunState.h"
#include "RunStatistics.h"
#include "RunManager.generated.h"

class AActor;
class ADebrisDataActor;
class UBXEAmmoUnlockManager;
class UBXEDamageUnlockManager;
class UBXEGameStateComponent;
class UBXELogicUnlockManager;
class UBXENegotiationManager;
class UBXEUnlockBase;
class UBXEUnlockRarity;
class UBiome;
class UFSDEventsHandler;
class UReadyUpManager;
class URiskVector;
class URun;
class URunHistoryManager;
class URunTemplate;
class UStage;
class UStageTemplateDifficulty;
class UUnlockCollectionTag;
class UVoteManager;
UCLASS(Blueprintable, DefaultToInstanced)
class URunManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRunManagerStageDelegate, UStage*, Stage);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRunManagerRunDelegate, URun*, Run);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRunManagerDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChipsChangedSignature, int32, NumberOfPoints, int32, change);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnChipsChangedSignature OnChipsChanged;
    FDelegate OnRewardTreeReset;
    FRunManagerDelegate OnActiveRunChangedDelegate;
    FRunManagerRunDelegate OnGeneratedRun;
    FRunManagerStageDelegate OnActiveStageChanged;
    FDelegate OnExpeniteMined;
 
    FIntDelegate OnXpChanged;
    FIntDelegate OnLevelChanged;
    FDelegate OnArtifactChanged;
    FDelegate OnPotentExpeniteChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBXENegotiationManager* NegotiationManager;
    UReadyUpManager* ReadyUpManager;
    UVoteManager* VoteManager;
    URunHistoryManager* RunHistoryManager;
    UBXELogicUnlockManager* LogicUnlockManager;
    UBXEDamageUnlockManager* DamageUnlockManager;
    UBXEAmmoUnlockManager* AmmoUnlockManager;
    UFSDEventsHandler* EventsHandler;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEGameStateComponent* GameStateComponent;
    FRunState RunState;
    FRunStatistics RunStatistics;
    URun* ActiveRun;
    float CurrentCaveDepth;
    int32 ObjectiveRewardRegistered;
    TMap<FGuid, TSoftObjectPtr<UBXEUnlockBase>> Unlocks;
    TMap<FGuid, TSoftObjectPtr<UBXEUnlockRarity>> Rarities;
    FRandomStream UnlockRandomStream;
    FRandomStream EquipmentRandomStream;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> LevelUpBlockers;
    URunManager();
    UFUNCTION(BlueprintCallable)
    void StartRun(const FRunCreationParameters& Parameters);
    void SetRiskVectorsInBugReporter();
    void RemoveLevelUpBlocker(AActor* blocker);
    void PotentExpeniteDispensed();
    void PotentExpeniteCollected();
    void OnObjectivesChanged();
    bool MoveToNextStage();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContext"))
    void MissionShout(UObject* WorldContext, EMissionShoutID InShoutID) const;
    void MarkActiveStageComplete();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStageComplete(int32 BranchIndex) const;
    bool IsSecondToLastStageActive() const;
    bool IsLevelUpBlocked();
    bool IsLastStageActive() const;
    bool IsFirstStageActive() const;
    bool IsActiveStageCompleted() const;
    bool IsActive() const;
    void IncrementTotalArtifactGiversSpawned();
    bool HaveActiveStage() const;
    bool HaveActiveRun() const;
    bool HasUnclaimedRewards() const;
    bool HasPendingPotentExpeniteUpgrade() const;
    bool HasPendingArtifactUpgrade() const;
    int32 GetXPToChipConversionRate() const;
    float GetWaveIntervalMultiplier() const;
    UVoteManager* GetVoteManager() const;
    int32 GetUnclaimedRewards() const;
    void GetTotalObjectivesCompleted(int32& OutCount) const;
    int32 GetTotalArtifactGiversSpawned() const;
    FString GetStageSeedString() const;
    FText GetStageName(int32 BranchIndex) const;
    UStage* GetStageAtIndex(const int32 StageIndex) const;
    int32 GetRunXp() const;
    int32 GetRunSeed() const;
    URunHistoryManager* GetRunHistoryManager() const;
    int32 GetRewardsAwarded() const;
    UReadyUpManager* GetReadyUpManager() const;
    int32 GetRandomEquipmentSeed() const;
    int32 GetPotentExpeniteDispensed() const;
    int32 GetPotentExpeniteCollected() const;
    void GetPerObjectiveXP(int32& perObjective) const;
    void GetPerKillXP(int32& perKill) const;
    void GetPerExpeniteXP(int32& perExpenite) const;
    int32 GetNumberOfStages() const;
    int32 GetNumberOfCompletedStages() const;
    int32 GetNumberOfClaimableChips() const;
    int32 GetNumberOfChips() const;
    float GetNextLevelXP() const;
    UBXENegotiationManager* GetNegotiationManager() const;
    TSoftClassPtr<ADebrisDataActor> GetModeExtraDebris() const;
    int32 GetLevel() const;
    void GetExpeniteCollected(int32& outCollected) const;
    float GetEnemyResistanceModifier(EEnemyHealthScaling healthScaling) const;
    float GetEnemyDamageModifier() const;
    float GetCurrentXP() const;
    float GetCurrentPotentialXP() const;
    float GetCurrentPotentialLevelProgress() const;
    float GetCurrentLevelProgress() const;
    UBiome* GetBiomeFromStageID(int32 StageID) const;
    int32 GetArtifactsDispensed() const;
    int32 GetArtifactsCollected() const;
    UStageTemplateDifficulty* GetActiveStageDifficulty() const;
    UStage* GetActiveStage() const;
    URunTemplate* GetActiveRunTemplate() const;
    FText GetActiveRunName() const;
    URun* GetActiveRun() const;
    UBiome* GetActiveBiome() const;
    void GetAccumulatedObjectiveXP(int32& perPrimary) const;
    void ClearRun();
    int32 ClaimAllClaimableChips();
    void CheatPrintStages();
    bool Cheat_DroneApplyUnlock(UBXEUnlockBase* InUnlock);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void BeginNegotiation(UUnlockCollectionTag* InCollectionTag, int32 Seed);
    void ArtifactDispensed();
    void ArtifactCollected();
    void AddReward();
    void AddLevelUpBlocker(AActor* blocker);
    int32 AddChips(int32 InAmount);
    void AddAdditionalRiskVector(URiskVector* RiskVector);
};
