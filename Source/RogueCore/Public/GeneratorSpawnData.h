#pragma once
#include "CoreMinimal.h"
#include "GeneratorSpawnData.generated.h"

USTRUCT(BlueprintType)
struct FGeneratorSpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    float MaxDistance;
    int32 GeneratorsToSpawn;
    ROGUECORE_API FGeneratorSpawnData();
};
