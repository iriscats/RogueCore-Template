#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "Templates/SubclassOf.h"
#include "StageSeedParameters.generated.h"

class UBiome;
class UMissionDNA;
class UPrimaryMutator;
class URunTemplate;
USTRUCT(BlueprintType)
struct FStageSeedParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveSeed;
    
    ERunDepth ActiveDepth;
    URunTemplate* ActiveRun;
    UBiome* ActiveBiome;
    TSubclassOf<UMissionDNA> ActiveDNA;
    int32 ActiveStage;
    UPrimaryMutator* ActiveMutator;
    ROGUECORE_API FStageSeedParameters();
};
