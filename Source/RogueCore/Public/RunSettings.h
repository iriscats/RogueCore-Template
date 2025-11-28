#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "PlanetGuaranteedRun.h"
#include "RandIntegerValue.h"
#include "Templates/SubclassOf.h"
#include "RunSettings.generated.h"

class UMissionDNA;
class UPrimaryMutator;
class URiskVector;
class URunTemplate;
UCLASS(Blueprintable)
class URunSettings : public UDataAsset {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URunTemplate*> AllRuns;
    
    TArray<UPrimaryMutator*> AllMutators;
    TArray<TSubclassOf<UMissionDNA>> AllDNA;
    TMap<TSoftObjectPtr<URiskVector>, TSoftObjectPtr<URiskVector>> IncompatibleRiskVectors;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval AmountOfOutOfRangeBiomes;
    int32 MaximumRunsPerBiome;
    TArray<FPlanetGuaranteedRun> GuaranteedRuns;
    TArray<FRandIntegerValue> AmountOfNormalRunsInEachZoneDepth1;
    TArray<FRandIntegerValue> AmountOfNormalRunsInEachZoneDepth2;
    TArray<FRandIntegerValue> AmountOfNormalRunsInEachZoneDepth3;
    TArray<FRandIntegerValue> AmountOfNormalRunsInEachZoneDepth4;
    TArray<FRandIntegerValue> AmountOfMutatedRunsInEachZoneDepth1;
    TArray<FRandIntegerValue> AmountOfMutatedRunsInEachZoneDepth2;
    TArray<FRandIntegerValue> AmountOfMutatedRunsInEachZoneDepth3;
    TArray<FRandIntegerValue> AmountOfMutatedRunsInEachZoneDepth4;
    TArray<URunTemplate*> RunsDepth1;
    TArray<URunTemplate*> RunsDepth2;
    TArray<URunTemplate*> RunsDepth3;
    TArray<URunTemplate*> RunsDepth4;
    TArray<UPrimaryMutator*> MutatorsDepth1;
    TArray<UPrimaryMutator*> MutatorsDepth2;
    TArray<UPrimaryMutator*> MutatorsDepth3;
    TArray<UPrimaryMutator*> MutatorsDepth4;
    URunSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<URunTemplate*> GetAllRuns() const;
    TArray<UPrimaryMutator*> GetAllMutators() const;
    TArray<TSubclassOf<UMissionDNA>> GetAllDNA() const;
};
