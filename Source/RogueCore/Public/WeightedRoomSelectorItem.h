#pragma once
#include "CoreMinimal.h"
#include "WeightedRoomSelectorItem.generated.h"

class URoomGenerator;
USTRUCT(BlueprintType)
struct FWeightedRoomSelectorItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URoomGenerator* Room;
    
    float Weight;
    ROGUECORE_API FWeightedRoomSelectorItem();
};
