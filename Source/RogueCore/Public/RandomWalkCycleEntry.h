#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "RandomWalkCycleEntry.generated.h"

class UAnimSequence;
USTRUCT(BlueprintType)
struct FRandomWalkCycleEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomSelectionWeight;
    
    FRandRange Duration;
    UAnimSequence* Animation;
    float CoolDown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastTimePlayed;
    ROGUECORE_API FRandomWalkCycleEntry();
};
