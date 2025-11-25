#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ERunDepth.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "Templates/SubclassOf.h"
#include "BXEPLSTester.generated.h"

class UBiome;
class UMissionDNA;
class UPlanetZone;
class URunTemplate;
class UStageTemplateDifficulty;
class UStageTemplateOverride;
UCLASS(Blueprintable, NoExport)
class ABXEPLSTester : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FullSeedString;

    int32 Seed;
    int32 SimulatePlayerCount;
    ERunDepth RunDepth;
    URunTemplate* RunTemplate;
    int32 ActiveStage;
    UBiome* Biome;
    UPlanetZone* PlanetZoneOverride;
    UStageTemplateDifficulty* DifficultyOverride;
    UStageTemplateOverride* BossOverride;
    TSubclassOf<UMissionDNA> DnaOverride;
    FRunObjectiveOverrides ObjectiveOverrides;
    FRunMutatorOverrides MutatorOverrides;
 
    ABXEPLSTester(const FObjectInitializer& ObjectInitializer);
};
