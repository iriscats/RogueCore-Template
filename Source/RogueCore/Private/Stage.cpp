#include "Stage.h"
#include "Templates/SubclassOf.h"

UStage::UStage() {
    this->RunSeed = -1;
    this->StageIndex = -1;
    this->StageCompletionRequirement = 100.00f;
}

bool UStage::IsLocked(const AFSDPlayerController* Player) const {
    return false;
}

bool UStage::IsDeepDive() const {
    return false;
}

EStageType UStage::GetType() const {
    return EStageType::Cave;
}

UStageTemplate* UStage::GetTemplate() const {
    return NULL;
}

int32 UStage::GetStageSeed() const {
    return 0;
}

float UStage::GetStageScale() const {
    return 0.0f;
}

FText UStage::GetStageName() const {
    return FText::GetEmpty();
}

int32 UStage::GetStageIndex() const {
    return 0;
}

UMissionDNA* UStage::GetStageDNA() const {
    return NULL;
}

TArray<TSubclassOf<UObjective>> UStage::GetSecondaryObjectives() const {
    return TArray<TSubclassOf<UObjective>>();
}

TArray<UMutator*> UStage::GetSecondaryMutators() const {
    return TArray<UMutator*>();
}

FString UStage::GetSafeRoomLevel() const {
    return TEXT("");
}

int32 UStage::GetRunSeed() const {
    return 0;
}

TArray<URiskVector*> UStage::GetRiskVectorsSorted() const {
    return TArray<URiskVector*>();
}

TArray<URiskVector*> UStage::GetRiskVectors() const {
    return TArray<URiskVector*>();
}

TSubclassOf<UObjective> UStage::GetPrimaryObjective() const {
    return NULL;
}

UPrimaryMutator* UStage::GetPrimaryMutator() const {
    return NULL;
}

TArray<int32> UStage::GetNextStageIndexes() const {
    return TArray<int32>();
}

TArray<UMutator*> UStage::GetMutators(TSubclassOf<UMutator> mutatorClass) const {
    return TArray<UMutator*>();
}

TArray<TSubclassOf<UObjective>> UStage::GetExpeniteObjectives() const {
    return TArray<TSubclassOf<UObjective>>();
}

FObjectiveMissionIcon UStage::GetExpeniteObjectiveIcon() const {
    return FObjectiveMissionIcon{};
}

TSubclassOf<UMissionDNA> UStage::GetDNA() const {
    return NULL;
}

TSoftClassPtr<AProceduralSetup> UStage::GetCaveGenerator() const {
    return NULL;
}

UBiome* UStage::GetBiome() const {
    return NULL;
}

AProceduralSetup* UStage::CreateCaveGenerator() const {
    return NULL;
}

bool UStage::AreStagesEqual(const UStage* Other) const {
    return false;
}


