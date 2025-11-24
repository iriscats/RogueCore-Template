#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "Templates/SubclassOf.h"
#include "PlanetGuaranteedRun.generated.h"

class UBiome;
class UMissionDNA;
class UPlanetZone;
class UPrimaryMutator;
class URunTemplate;
class UStageComplexity;
class UStageDuration;
USTRUCT(BlueprintType)
struct FPlanetGuaranteedRun {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERunDepth RunDepth;
    
    URunTemplate* Run;
    UBiome* Biome;
    UPlanetZone* PlanetZone;
    UStageDuration* Duration;
    UStageComplexity* Complexity;
    TSubclassOf<UMissionDNA> DNA;
    UPrimaryMutator* Mutator;
    bool UseRandomMutator;
    ROGUECORE_API FPlanetGuaranteedRun();
};
