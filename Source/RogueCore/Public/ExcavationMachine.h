#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ExcavationReward.h"
#include "PredictedRewards.h"
#include "RewardsUpdatedDelegate.h"
#include "ExcavationMachine.generated.h"

class USceneComponent;
UCLASS(Blueprintable)
class AExcavationMachine : public AActor {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* GemSpawnPoint;

    USceneComponent* RootScene;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExcavationReward> Rewards;
    FExcavationReward ExpeniteChunkReward;
    float SpawnChanceExpenite;
    float PostSpawnChanceExpenite;
    float SpawnChanceMultiplierExpenite;
    float ResourceAmountExpenite;
    FExcavationReward WorthlessChunkReward;
    FRandomStream RandomStream;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Seed, meta=(AllowPrivateAccess=true))
    int32 Seed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RemainingGemCount, meta=(AllowPrivateAccess=true))
    int32 RemainingGemCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PredictedRewards, meta=(AllowPrivateAccess=true))
    FPredictedRewards PredictedRewards;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRewardsUpdated OnRewardsUpdated;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VisualsEnabled, meta=(AllowPrivateAccess=true))
    bool VisualsEnabled;

 
    AExcavationMachine(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateFutureRewards(int32 InDepth);
    void SpawnExcavationReward();
    void SetVisualsEnabled(bool InEnabled);
    void SetRemainingGemCount(int32 InGemAmount);
    void SetExpenitePayout(float InPayout);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepVisualsEnabled(bool Enabled);
    void OnRepGemAmount();
    UFUNCTION()
    void OnRep_VisualsEnabled();
    UFUNCTION()
    void OnRep_Seed();
    UFUNCTION()
    void OnRep_RemainingGemCount();
    UFUNCTION()
    void OnRep_PredictedRewards();
};
