#include "RunGenerationManager.h"

URunGenerationManager::URunGenerationManager() {
}

TArray<UStage*> URunGenerationManager::GetStages(int32 Seed) {
    return TArray<UStage*>();
}

TArray<UStage*> URunGenerationManager::GetAvailableStages() {
    return TArray<UStage*>();
}

TArray<FGeneratedRunsForBiome> URunGenerationManager::GenerateRuns(const int32 Seed) {
    return TArray<FGeneratedRunsForBiome>();
}


