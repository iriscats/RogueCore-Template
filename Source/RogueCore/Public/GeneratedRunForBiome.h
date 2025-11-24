#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "Templates/SubclassOf.h"
#include "GeneratedRunForBiome.generated.h"

class UBiome;
class UMissionDNA;
class UPlanetZone;
class UPrimaryMutator;
class URunTemplate;
USTRUCT(BlueprintType)
struct FGeneratedRunForBiome {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiome* Biome;
    
    UPlanetZone* PlanetZone;
    UPrimaryMutator* Mutator;
    ERunDepth RunDepth;
    TSubclassOf<UMissionDNA> DNA;
    URunTemplate* Run;
    int32 RunSeed;
    ROGUECORE_API FGeneratedRunForBiome();
};
