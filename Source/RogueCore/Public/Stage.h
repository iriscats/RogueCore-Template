#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EStageType.h"
#include "GMMutatorItem.h"
#include "ObjectiveMissionIcon.h"
#include "StageSetup.h"
#include "Templates/SubclassOf.h"
#include "Stage.generated.h"

class AFSDPlayerController;
class AProceduralSetup;
class UBiome;
class UMissionDNA;
class UMutator;
class UObjective;
class UPrimaryMutator;
class URiskVector;
class UStage;
class UStageTemplate;
UCLASS(Blueprintable, DefaultToInstanced)
class ROGUECORE_API UStage : public UObject {
    GENERATED_BODY()

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStageDelegate);
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStageDelegate OnStageSetupChangedDelegate;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 RunSeed;
    int32 StageIndex;
    FStageSetup StageSetup;
    TMap<TSubclassOf<UMutator>, FGMMutatorItem> Mutators;
    TArray<URiskVector*> RiskVectors;
    float StageCompletionRequirement;
    UStage();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked(const AFSDPlayerController* Player) const;
    bool IsDeepDive() const;
    EStageType GetType() const;
    UStageTemplate* GetTemplate() const;
    int32 GetStageSeed() const;
    float GetStageScale() const;
    FText GetStageName() const;
    int32 GetStageIndex() const;
    UMissionDNA* GetStageDNA() const;
    TArray<TSubclassOf<UObjective>> GetSecondaryObjectives() const;
    TArray<UMutator*> GetSecondaryMutators() const;
    FString GetSafeRoomLevel() const;
    int32 GetRunSeed() const;
    TArray<URiskVector*> GetRiskVectorsSorted() const;
    TArray<URiskVector*> GetRiskVectors() const;
    TSubclassOf<UObjective> GetPrimaryObjective() const;
    UPrimaryMutator* GetPrimaryMutator() const;
    TArray<int32> GetNextStageIndexes() const;
    TArray<UMutator*> GetMutators(TSubclassOf<UMutator> mutatorClass) const;
    TArray<TSubclassOf<UObjective>> GetExpeniteObjectives() const;
    FObjectiveMissionIcon GetExpeniteObjectiveIcon() const;
    TSubclassOf<UMissionDNA> GetDNA() const;
    TSoftClassPtr<AProceduralSetup> GetCaveGenerator() const;
    UBiome* GetBiome() const;
    AProceduralSetup* CreateCaveGenerator() const;
    bool AreStagesEqual(const UStage* Other) const;
};
