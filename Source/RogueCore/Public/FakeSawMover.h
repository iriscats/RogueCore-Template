#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FakeSawMover.generated.h"

class UCurveFloat;
USTRUCT(BlueprintType)
struct FFakeSawMover {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector PrevPos = FVector::ZeroVector;
    
    FVector NextPos;
    FVector Velocity;
    FPlane Plane;
    UCurveFloat* VelOverTime;
    float SpeedCof;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickRate = 0.0f;
    float TickTime;
    float AccumulatedTime;
    float TotalTime;
    bool Moving;
    float GravityTimer;

};
