#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ETrackBuildPlacementState.h"
#include "TrackBuilderPoint.generated.h"

class UTrackBuilderConnectPoint;
USTRUCT(BlueprintType)
struct FTrackBuilderPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInitialized;
    
    ETrackBuildPlacementState PlacementState;
    FVector_NetQuantize Location;
    FVector_NetQuantize EulerRotation;
    bool bPointValid;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrackBuilderConnectPoint> ConnectPoint;
    ROGUECORE_API FTrackBuilderPoint();
};
