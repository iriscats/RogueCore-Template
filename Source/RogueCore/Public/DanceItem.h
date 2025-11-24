#pragma once
#include "CoreMinimal.h"
#include "DanceItem.generated.h"

class UAnimSequence;
USTRUCT(BlueprintType)
struct FDanceItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* DanceMove;
    
    UAnimSequence* DanceMoveWithBeer;
    ROGUECORE_API FDanceItem();
};
