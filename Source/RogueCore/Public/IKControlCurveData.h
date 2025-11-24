#pragma once
#include "CoreMinimal.h"
#include "IKControlCurveData.generated.h"

USTRUCT(BlueprintType)
struct FIKControlCurveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurveName;
    
    FName JointName;
    bool CorrectToTerrain;
    float RayUpOffset;
    float RayMaxDistance;
    float ExplicitBoneGroundOffset;
    ROGUECORE_API FIKControlCurveData();
};
