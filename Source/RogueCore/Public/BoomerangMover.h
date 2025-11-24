#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoomerangMover.generated.h"

class UCurveVector;
USTRUCT(BlueprintType)
struct FBoomerangMover {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator StartRotation;
    
    FVector PrevPos;
    FVector NextPos;
    FVector Velocity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    float TimeScale;
    float TickRate;
    float TickTime;
    float AccumulatedTime;
    float TotalTime;
    float StartSmoothTime;
    UCurveVector* ArcCurve;
    bool IsGoingBack;
    ROGUECORE_API FBoomerangMover();
};
