#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoomerangSyncer.generated.h"

USTRUCT(BlueprintType)
struct FBoomerangSyncer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector PrevPos;
    
    FVector NextPos;
    FVector Velocity;
    bool IsGoingBack;
    float TotalTime;
    ROGUECORE_API FBoomerangSyncer();
};
