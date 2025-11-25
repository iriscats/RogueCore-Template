#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "PathObstacle.h"
#include "NoisyPathfinderTest.generated.h"

class ADeepCSGWorld;
class UFloodFillSettings;
class UTunnelParameters;
class UTunnelSegmentSetting;
UCLASS(Blueprintable)
class ANoisyPathfinderTest : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Start;
    
    FVector End;
    FVector StartDirection;
    FVector EndDirection;
    float DirectionDistance;
    float DirectionPenalty;
    float ZPenaltyPower;
    float ZPenaltyScale;
    float DistancePenaltyScale;
    float RandomPenaltyScale;
    TArray<FPathObstacle> Obstacles;
    UTunnelSegmentSetting* TunnelSettings;
    UTunnelParameters* TunnelParameters;
    int32 StepSize;
    bool Realtime;
    bool CarvePath;
    bool CanDiagonal;
    UFloodFillSettings* FloodFillSettings;
    ADeepCSGWorld* CSGWorld;
    ANoisyPathfinderTest(const FObjectInitializer& ObjectInitializer);
};
