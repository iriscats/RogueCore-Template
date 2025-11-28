#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "DelegateEventDelegate.h"
#include "ProgressChangedSigDelegate.h"
#include "StageCompleteSigDelegate.h"
#include "Templates/SubclassOf.h"
#include "GameEvent.generated.h"

class AEventStarterButton;
class AProceduralSetup;
class ARessuplyPod;
class UChildActorComponent;
class UDebrisPositioning;
class UDialogDataAsset;
UCLASS(Blueprintable)
class ROGUECORE_API AGameEvent : public AActor, public IGameplayTagAssetInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent EventTriggeredDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent EventFinishedDelegate;
    FStageCompleteSig StageCompleteDelegate;
    FProgressChangedSig ProgressChangedDelegate;
    FProgressChangedSig OnProgressBarChanged;
    FProgressChangedSig TimeProgressChanged;
    FStageCompleteSig ObjectivesPerStageChanged;

    TArray<AEventStarterButton*> StarterObjects;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bGameEventSetup;
    FText EventName;
    FText ObjectiveText;
    FName AnalyticsName;
    FGameplayTagContainer GameplayTags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* StartEventObject;
    UDialogDataAsset* EventTriggeredShout;
    UDialogDataAsset* EventFinishedShout;
    UDialogDataAsset* EventFailedShout;
    float EventTriggeredShoutDelay;
    float EventFinishedShoutDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_StageProgress, meta=(AllowPrivateAccess=true))
    float StageProgress;
    float TimeLimit;
    float DelayUITime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ObjectivesPerStage, meta=(AllowPrivateAccess=true))
    int32 objectivesPerStage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsEventStartersActive, meta=(AllowPrivateAccess=true))
    bool EventStartersActive;
    bool StopScriptedWavesWhileActive;
    bool StopNormalWavesWhileActive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EventStarted, meta=(AllowPrivateAccess=true))
    bool EventStarted;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FailedEvent, meta=(AllowPrivateAccess=true))
    bool FailedEvent;
    bool ShowRemainingTimeOnHUD;
    bool ShowScoreStatusOnHUD;
    bool ShowProgressBar;
    float ProgressBarPct;
    bool SkipEventStarters;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EventParticipants, meta=(AllowPrivateAccess=true))
    TArray<AActor*> EventParticipants;
    AGameEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TrySetupGameEvent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TriggerEvent();
    void StartShout();
    void StageObjectiveCompleted();
    ARessuplyPod* SpawnEventPod(TSubclassOf<ARessuplyPod> podClass, const FVector& aSpawnLocation, int32 Delay);
    AActor* SpawnEventActor(TSubclassOf<AActor> eventActorClass, const FTransform& aSpawnLocation);
    void SetStageProgress(float Progress);
    void SetProgressBarPct(float InPct);
    void SetObjectivesPerStage(int32 NewObjectivesPerStage);
    void RemoveParticipant(AActor* participant);
    void OnStarterObjectUsed(AEventStarterButton* eventStarter);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStageProgress(float Progress);
public:
    void OnStageComplete(int32 Stage);
    UFUNCTION()
    void OnRep_StageProgress();
    UFUNCTION()
    void OnRep_ObjectivesPerStage();
    UFUNCTION()
    void OnRep_IsEventStartersActive();
    UFUNCTION()
    void OnRep_FailedEvent();
    UFUNCTION()
    void OnRep_EventStarted();
    UFUNCTION()
    void OnRep_EventParticipants();
    void OnEventTriggered();
    void OnEventFinished(bool eventSuccess);
    void OnEventBooted();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventCompleted() const;
    bool IsEventActive() const;
    float GetStageProgress() const;
    bool GetShowTimeOnHUD() const;
    bool GetShowScoreOnHUD() const;
    bool GetShowProgressBar() const;
    FText GetObjectiveText() const;
    int32 GetObjectivesPerStage() const;
    FText GetEventName() const;
    bool GetEventFailed() const;
    float GetDelayUITime() const;
    void EndShout();
    FTransform DebreePositionPoint(AProceduralSetup* setup, const FVector& fromLocation, float MinDistance, float desiredDistance, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, float maxPathLength);
    void BootUpEvent();
    void AddStageProgress(float progressToAdd);
    // IGameplayTagAssetInterface implementation
    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override {
        TagContainer = GameplayTags;
    }

    // Blueprint-friendly versions
    UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameplayTags")
    FGameplayTagContainer BP_GetOwnedGameplayTags() const {
        return GameplayTags;
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameplayTags")
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const {
        return GameplayTags.HasTag(TagToCheck);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameplayTags")
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const {
        return GameplayTags.HasAny(TagContainer);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameplayTags")
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const {
        return GameplayTags.HasAll(TagContainer);
    }
};
