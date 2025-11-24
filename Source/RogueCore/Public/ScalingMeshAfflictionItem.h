#pragma once
#include "CoreMinimal.h"
#include "EFrozenBitsSize.h"
#include "RandRange.h"
#include "ScalingMeshAfflictionItem.generated.h"

USTRUCT(BlueprintType)
struct FScalingMeshAfflictionItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    FRandRange MeshScale;
    EFrozenBitsSize FrozenBitsSize;
    float ChanceToSpawn;
    ROGUECORE_API FScalingMeshAfflictionItem();
};
