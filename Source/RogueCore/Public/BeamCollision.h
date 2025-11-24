#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BeamCollision.generated.h"

USTRUCT(BlueprintType)
struct FBeamCollision {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBeamBlocked;
    
    float BeamHitDistance;
    FVector FinalTraceStart;
    FVector FinalTraceEnd;
    ROGUECORE_API FBeamCollision();
};
