#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ERunDepth.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "Templates/SubclassOf.h"
#include "PLSTester.generated.h"

class UBiome;
class UDifficultySetting;
class UMissionDNA;
class UPlanetZone;
class URunTemplate;
class USpecialEvent;
class UStageTemplateDifficulty;
class UStageTemplateOverride;
UCLASS(Blueprintable)
class APLSTester : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FullSeedString;
    
    int32 PLSSeed;
    int32 missionSeed;
    int32 globalSeed;
    USpecialEvent* SpecialEvent;
    URunTemplate* RunTemplate;
    ERunDepth RunDepth;
    int32 ActiveStage;
    UBiome* Biome;
    UPlanetZone* PlanetZoneOverride;
    TSubclassOf<UMissionDNA> DnaOverride;
    UStageTemplateDifficulty* DifficultyOverride;
    UStageTemplateOverride* BossOverride;
    FRunObjectiveOverrides ObjectiveOverrides;
    FRunMutatorOverrides MutatorOverrides;
    UDifficultySetting* OverrideDifficulty;
    int32 SimulatePlayerCount;
    FText CustomMissionName;
    APLSTester(const FObjectInitializer& ObjectInitializer);
};
