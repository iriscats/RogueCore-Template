#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EndEffector.generated.h"

USTRUCT(BlueprintType)
struct FEndEffector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EndBone;
    
    FVector position;
    FVector GroundCorrection;
    float PositionAlpha;
    int32 PositionDepth;
    FQuat Rotation;
    float RotationAlpha;
    int32 RotationDepth;
    float Pull;
    ROGUECORE_API FEndEffector();
};
