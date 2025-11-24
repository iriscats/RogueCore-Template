#pragma once
#include "CoreMinimal.h"
#include "CollectableSpawnableItem.generated.h"

class UCollectableResourceData;
USTRUCT(BlueprintType)
struct FCollectableSpawnableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCollectableResourceData* Resource;
    
    int32 amount;
    ROGUECORE_API FCollectableSpawnableItem();
};
