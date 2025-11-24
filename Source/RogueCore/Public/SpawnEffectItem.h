#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ECreatureSize.h"
#include "SpawnEffectItem.generated.h"

USTRUCT(BlueprintType)
struct FSpawnEffectItem {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureSize CreatureSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    FVector_NetQuantizeNormal CompressedRotation;
    float EndTime;
    ROGUECORE_API FSpawnEffectItem();
};
