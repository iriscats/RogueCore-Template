#pragma once
#include "CoreMinimal.h"
#include "EDebrisColliderType.h"
#include "TerrainPlacementDebugGroup.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementDebugGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    EDebrisColliderType CapsuleType;
    int32 Good;
    int32 Bad;
    ROGUECORE_API FTerrainPlacementDebugGroup();
};
