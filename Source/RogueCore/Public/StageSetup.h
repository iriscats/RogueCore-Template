#pragma once
#include "CoreMinimal.h"
#include "EStageType.h"
#include "Templates/SubclassOf.h"
#include "StageSetup.generated.h"

class ADebrisDataActor;
class AProceduralSetup;
class UBiome;
class UDebrisActorComponent;
class UMissionDNA;
class UMutator;
class UObjective;
class UPrimaryMutator;
class URiskVector;
class UStageTemplate;
class UStageTemplateDifficulty;
USTRUCT(BlueprintType)
struct FStageSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StageSeed;
    
    UStageTemplate* StageTemplate;
    UBiome* Biome;
    EStageType Type;
    TArray<int32> NextStageIndexes;
    TSoftClassPtr<AProceduralSetup> ProceduralActor;
    TSoftClassPtr<ADebrisDataActor> DebrisActor;
    TArray<TSoftClassPtr<UDebrisActorComponent>> DebrisComponents;
    UStageTemplateDifficulty* Difficulty;
    TSubclassOf<UObjective> PrimaryObjective;
    TArray<TSubclassOf<UObjective>> SecondaryObjectives;
    TArray<TSubclassOf<UObjective>> ExpeniteObjectives;
    UPrimaryMutator* PrimaryMutator;
    TArray<UMutator*> SecondaryMutators;
    TArray<URiskVector*> RiskVectors;
    TSubclassOf<UMissionDNA> StageDNA;
    FString SafeRoomLevel;
    ROGUECORE_API FStageSetup();
};
