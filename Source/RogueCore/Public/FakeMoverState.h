#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FakeMoverState.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FFakeMoverState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TickTime;
    FVector PrevPos;
    FVector NextPos;
    FVector PrevSurfaceNormal;
    FVector NextSurfaceNormal;
    float AccumulatedTime;
    AActor* Target;
    FVector Velocity;
    bool NearSurface;
    float SignedDistToSurface;
    ROGUECORE_API FFakeMoverState();
};
