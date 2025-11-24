#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "Templates/SubclassOf.h"
#include "RunCreationParameters.generated.h"

class ADebrisDataActor;
class AProceduralSetup;
class UBiome;
class UMissionDNA;
class UPlanetZone;
class URunTemplate;
class UStageTemplateDifficulty;
class UStageTemplateOverride;
USTRUCT(BlueprintType)
struct FRunCreationParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERunDepth RunDepth;
    
    URunTemplate* RunTemplate;
    int32 RunSeedOverride;
    int32 ActiveStageOverride;
    UBiome* BiomeOverride;
    UPlanetZone* PlanetZoneOverride;
    UStageTemplateDifficulty* DifficultyOverride;
    FRunMutatorOverrides MutatorOverrides;
    FRunObjectiveOverrides ObjectiveOverrides;
    UStageTemplateOverride* BossOverride;
    TSoftClassPtr<AProceduralSetup> CaveGeneratorOverride;
    TSoftClassPtr<ADebrisDataActor> DebrisActorOverride;
    TSubclassOf<UMissionDNA> DnaOverride;
    ROGUECORE_API FRunCreationParameters();
};
