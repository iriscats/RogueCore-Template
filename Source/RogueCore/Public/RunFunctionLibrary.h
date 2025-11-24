#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EPlanetBiomeState.h"
#include "ERunDepth.h"
#include "GeneratedRunForBiome.h"
#include "RunBranchSet.h"
#include "Templates/SubclassOf.h"
#include "RunFunctionLibrary.generated.h"

class UBiome;
class UMissionDNA;
class UMutator;
class UObject;
class UPlanetZone;
class UPrimaryMutator;
class URiskVector;
class URun;
class URunTemplate;
class UStageComplexity;
class UStageDuration;
class UStageTemplateOverride;
UCLASS(Blueprintable)
class ROGUECORE_API URunFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URunFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsBiomeLocked(const UObject* WorldContext, const UBiome* BiomeToCheck);
    
    static bool HavePlayerUnlockedRunTemplate(const UObject* WorldContext, const URunTemplate* RunTemplate);
    static bool HavePlayerUnlockedRun(const UObject* WorldContext, const FGeneratedRunForBiome& GeneratedRun);
    static bool HavePlayerUnlockedMutatedRuns(const UObject* WorldContext);
    static bool HavePlayerUnlockedDuration(const UObject* WorldContext, const UStageDuration* Duration);
    static bool HavePlayerUnlockedDepth(const UObject* WorldContext, const ERunDepth Depth);
    static bool HavePlayerUnlockedComplexity(const UObject* WorldContext, const UStageComplexity* Complexity);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetStageTemplateOverrideAssetName(const TSoftObjectPtr<UStageTemplateOverride>& Override);
    static int32 GetRunDepthIndex(const ERunDepth RunDepth);
    static FString GetRiskVectorAssetName(const TSoftObjectPtr<URiskVector>& RiskVector);
    static FString GetPrimaryMutatorAssetName(const TSoftObjectPtr<UPrimaryMutator>& Mutator);
    static FString GetMutatorAssetName(const TSoftObjectPtr<UMutator>& Mutator);
    static UMissionDNA* GetDnaClassDefaultObject(const TSubclassOf<UMissionDNA> DnaClass);
    static FString GetDnaAssetName(const TSoftClassPtr<UMissionDNA>& DNA);
    static void GetBiomeStatus(const UObject* WorldContext, const UBiome* Biome, bool& IsLocked, bool& IsOutOfRange, int32 Seed);
    static EPlanetBiomeState GetBiomeState(const UObject* WorldContext, const UBiome* Biome, const int32 MapSeed);
    static int32 GetAmountOfRunsInBiome(const UObject* WorldContext, const UBiome* Biome, const ERunDepth Depth, const int32 MapSeed);
    static int32 GetAmountOfMutatedRunsInBiome(const UObject* WorldContext, const UBiome* Biome, const ERunDepth Depth, const int32 MapSeed);
    static TArray<URunTemplate*> GetAllRunTemplates();
    static TArray<ERunDepth> GetAllRunDepths();
    static TArray<UPrimaryMutator*> GetAllMutators();
    static TArray<TSubclassOf<UMissionDNA>> GetAllDNA();
    static TArray<UBiome*> GetAllBiomes();
    static float GetActiveHazardBonus(const UObject* WorldContext);
    UFUNCTION(BlueprintCallable)
    static FText GenerateRunName(const int32 RunSeed);
    static UPlanetZone* FindPlanetZone(const UBiome* Biome);
    static TArray<FRunBranchSet> ComputeBranchSetsFromTemplate(const URunTemplate* RunTemplate, const ERunDepth Depth);
    static TArray<FRunBranchSet> ComputeBranchSetsFromRun(const URun* Run);
};
