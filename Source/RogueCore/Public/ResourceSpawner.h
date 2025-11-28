#pragma once
#include "CoreMinimal.h"
#include "RandFloatInterval.h"
#include "ResourceSpawner.generated.h"

class UGenericMutator;
class UResourceData;
USTRUCT(BlueprintType)
struct ROGUECORE_API FResourceSpawner {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    FRandFloatInterval AmountToSpawn;
    UGenericMutator* SpawnChanceMutator;
    FResourceSpawner();
};
