#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "PlagueObjective.generated.h"

class APlagueControlActor;
class APlagueInfectionNode;
class UDialogDataAsset;
class UEnemyWaveController;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlagueObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 StartPlagueAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentPlagueAmount, meta=(AllowPrivateAccess=true))
    int32 CurrentPlagueAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetPlagueAmount;
    float PercentageRequiredForCompletion;
    int32 SpawningTowersCount;
    UDialogDataAsset* NodeKilledShout;
    UDialogDataAsset* LastNodeKilledShout;
    UDialogDataAsset* OverridePrimaryObjCompletedShout_SelfCompleted;
    UDialogDataAsset* OverridePrimaryObjCompletedShout_SelfNotCompleted;
    bool AllPlagueCleaned;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    APlagueControlActor* PlagueController;
    TSoftClassPtr<APlagueControlActor> PlagueControllerClass;
    TArray<APlagueInfectionNode*> ActivePlagueCenters;
    TSoftClassPtr<UEnemyWaveController> ScriptedPlagueWave;
    float ScriptedPlagueWaveWeight;
    UPlagueObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentPlagueAmount(int32 OldAmount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<APlagueInfectionNode*> GetPlagueCenters();
};
