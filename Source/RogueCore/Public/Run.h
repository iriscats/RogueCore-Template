#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ERunDepth.h"
#include "EStageType.h"
#include "RunState.h"
#include "RunStatistics.h"
#include "Run.generated.h"

class UDifficultySetting;
class UMissionDNA;
class UPlanetZone;
class UPrimaryMutator;
class URunTemplate;
class UStage;
UCLASS(Blueprintable, DefaultToInstanced)
class URun : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRunDelegate);
    
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRunDelegate OnRunStateChangedDelegate;
    FRunDelegate OnRunStatisticsChangedDelegate;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRunState RunState;
    FRunStatistics RunStatistics;
    FText RunName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStage*> Stages;
    URun();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStageOfType(const int32 StageIndex, const EStageType StageType) const;
    bool IsStageComplete(int32 branchIdx) const;
    bool IsSecondToLastStage(int32 StageIndex) const;
    bool IsLastStage(int32 StageIndex) const;
    bool HaveStageAtIndex(const int32 StageIndex) const;
    URunTemplate* GetTemplate() const;
    UStage* GetStageAtIndex(const int32 StageIndex) const;
    int32 GetRunSeed() const;
    FText GetRunName() const;
    UPrimaryMutator* GetRunMutator() const;
    UPlanetZone* GetPlanetZone() const;
    int32 GetNumberOfStages() const;
    int32 GetNumberOfCompletedStages() const;
    TArray<int32> GetNextStageIndexes(int32 StageIndex) const;
    float GetHazardBonus() const;
    UMissionDNA* GetDNA() const;
    ERunDepth GetDepth() const;
    TArray<UStage*> GetAllStages() const;
    UStage* GetActiveStage() const;
    UPrimaryMutator* GetActivePrimaryMutator() const;
    UDifficultySetting* GetActiveDifficulty() const;
};
