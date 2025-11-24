#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ERunDepth.h"
#include "StageSetup.h"
#include "RunSetup.generated.h"

class UMissionDNA;
class UPlanetZone;
class UPrimaryMutator;
class URunTemplate;
USTRUCT(BlueprintType)
struct FRunSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid RunId;
    
    int32 RunSeed;
    ERunDepth RunDepth;
    URunTemplate* RunTemplate;
    UMissionDNA* RunDNA;
    UPrimaryMutator* RunMutator;
    UPlanetZone* PlanetZone;
    TArray<FStageSetup> Stages;
    ROGUECORE_API FRunSetup();
};
