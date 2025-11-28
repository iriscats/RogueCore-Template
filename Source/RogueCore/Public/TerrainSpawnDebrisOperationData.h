#pragma once
#include "CoreMinimal.h"

#include "TerrainSpawnDebrisOperationData.generated.h"

class UDebrisMesh;
USTRUCT(BlueprintType)
struct FTerrainSpawnDebrisOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    FVector Pos;
    float Radius;
    UDebrisMesh* Debris;
    ROGUECORE_API FTerrainSpawnDebrisOperationData();
};
