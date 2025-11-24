#include "RunFunctionLibrary.h"
#include "Templates/SubclassOf.h"

URunFunctionLibrary::URunFunctionLibrary() {
}

bool URunFunctionLibrary::IsBiomeLocked(const UObject* WorldContext, const UBiome* BiomeToCheck) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedRunTemplate(const UObject* WorldContext, const URunTemplate* RunTemplate) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedRun(const UObject* WorldContext, const FGeneratedRunForBiome& GeneratedRun) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedMutatedRuns(const UObject* WorldContext) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedDuration(const UObject* WorldContext, const UStageDuration* Duration) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedDepth(const UObject* WorldContext, const ERunDepth Depth) {
    return false;
}

bool URunFunctionLibrary::HavePlayerUnlockedComplexity(const UObject* WorldContext, const UStageComplexity* Complexity) {
    return false;
}

FString URunFunctionLibrary::GetStageTemplateOverrideAssetName(const TSoftObjectPtr<UStageTemplateOverride>& Override) {
    return TEXT("");
}

int32 URunFunctionLibrary::GetRunDepthIndex(const ERunDepth RunDepth) {
    return 0;
}

FString URunFunctionLibrary::GetRiskVectorAssetName(const TSoftObjectPtr<URiskVector>& RiskVector) {
    return TEXT("");
}

FString URunFunctionLibrary::GetPrimaryMutatorAssetName(const TSoftObjectPtr<UPrimaryMutator>& Mutator) {
    return TEXT("");
}

FString URunFunctionLibrary::GetMutatorAssetName(const TSoftObjectPtr<UMutator>& Mutator) {
    return TEXT("");
}

UMissionDNA* URunFunctionLibrary::GetDnaClassDefaultObject(const TSubclassOf<UMissionDNA> DnaClass) {
    return NULL;
}

FString URunFunctionLibrary::GetDnaAssetName(const TSoftClassPtr<UMissionDNA>& DNA) {
    return TEXT("");
}

void URunFunctionLibrary::GetBiomeStatus(const UObject* WorldContext, const UBiome* Biome, bool& IsLocked, bool& IsOutOfRange, int32 Seed) {
}

EPlanetBiomeState URunFunctionLibrary::GetBiomeState(const UObject* WorldContext, const UBiome* Biome, const int32 MapSeed) {
    return EPlanetBiomeState::Available;
}

int32 URunFunctionLibrary::GetAmountOfRunsInBiome(const UObject* WorldContext, const UBiome* Biome, const ERunDepth Depth, const int32 MapSeed) {
    return 0;
}

int32 URunFunctionLibrary::GetAmountOfMutatedRunsInBiome(const UObject* WorldContext, const UBiome* Biome, const ERunDepth Depth, const int32 MapSeed) {
    return 0;
}

TArray<URunTemplate*> URunFunctionLibrary::GetAllRunTemplates() {
    return TArray<URunTemplate*>();
}

TArray<ERunDepth> URunFunctionLibrary::GetAllRunDepths() {
    return TArray<ERunDepth>();
}

TArray<UPrimaryMutator*> URunFunctionLibrary::GetAllMutators() {
    return TArray<UPrimaryMutator*>();
}

TArray<TSubclassOf<UMissionDNA>> URunFunctionLibrary::GetAllDNA() {
    return TArray<TSubclassOf<UMissionDNA>>();
}

TArray<UBiome*> URunFunctionLibrary::GetAllBiomes() {
    return TArray<UBiome*>();
}

float URunFunctionLibrary::GetActiveHazardBonus(const UObject* WorldContext) {
    return 0.0f;
}

FText URunFunctionLibrary::GenerateRunName(const int32 RunSeed) {
    return FText::GetEmpty();
}

UPlanetZone* URunFunctionLibrary::FindPlanetZone(const UBiome* Biome) {
    return NULL;
}

TArray<FRunBranchSet> URunFunctionLibrary::ComputeBranchSetsFromTemplate(const URunTemplate* RunTemplate, const ERunDepth Depth) {
    return TArray<FRunBranchSet>();
}

TArray<FRunBranchSet> URunFunctionLibrary::ComputeBranchSetsFromRun(const URun* Run) {
    return TArray<FRunBranchSet>();
}


