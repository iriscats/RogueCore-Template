#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreditsReward.h"
#include "MissionShouts.h"
#include "ObjectiveMissionIcon.h"
#include "ObjectiveUpdatedSignatureDelegate.h"
#include "Templates/SubclassOf.h"
#include "Objective.generated.h"

class ADebrisDataActor;
class UBiome;
class UMissionStat;
class UObjective;
class UObjectiveWidget;
class UOptionalObjectiveWidget;
class UResourceData;
class UTexture2D;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UObjective : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectiveUpdatedSignature OnObjectiveUpdated;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UObjectiveWidget> ObjectiveWidgetClass;
    FMissionShouts MissionShouts;
    FText MissionDescription;
    int32 CompletionRewardInCredits;
    int32 CompletionRewardInXP;
    bool ScaleObjectiveToMission;
    bool bHasReturnObjective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool RequiredReturnObjectiveCompleted;
    bool ShowObjectiveInHUD;
    UMissionStat* ObjectiveCompletedStat;
    TSoftClassPtr<UOptionalObjectiveWidget> OptionalObjectiveWidgetClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsPrimaryObjective, meta=(AllowPrivateAccess=true))
    int32 IsPrimaryObjective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool bIsNeededForMissionCompletion;
    float MissionScale;
    TArray<UBiome*> BannedInBiomes;
    TArray<TSoftClassPtr<ADebrisDataActor>> ObjectiveDebris;
    UObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SignalObjectiveUpdated();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_StartTracking();
    UFUNCTION()
    void OnRep_IsPrimaryObjective();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsTutorialObjective() const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrimary() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsObjectiveResource(UResourceData* InResource) const;
    bool IsNeededForMissionCompletion() const;
    bool IsFinalBattle() const;
    bool IsCompleted() const;
    bool HasReplicated() const;
    TSubclassOf<UObjectiveWidget> GetWidgetClassOrDefault(TSubclassOf<UObjectiveWidget> DefaultWidgetClass);
    int32 GetRewardXP() const;
    FCreditsReward GetRewardCredits() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TSubclassOf<UOptionalObjectiveWidget> GetOptionalMissionWidget() const;
    FText GetObjectiveText() const;
    static UTexture2D* GetObjectiveIconFromClass(TSubclassOf<UObjective> objectiveClass);
    UTexture2D* GetObjectiveIcon() const;
    static FText GetObjectiveDescriptionFromClass(TSubclassOf<UObjective> objectiveClass, float missionLength);
    FText GetObjectiveDescription(float missionLength);
    static FString GetObjectiveAssetName(const TSoftClassPtr<UObjective>& Objective);
    static int32 GetObjectiveAmountFromClass(TSubclassOf<UObjective> objectiveClass, float missionLength);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetObjectiveAmount(float missionLength) const;
    FObjectiveMissionIcon GetMissionIcon() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetInMissionText() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetInMissionCounterText() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UTexture2D* GetInMissionCounterIcon() const;
};
