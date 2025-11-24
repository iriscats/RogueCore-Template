#pragma once
#include "CoreMinimal.h"

#include "LaserPointerTarget.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FLaserPointerTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult HitInfo;
    
    AActor* Target;
    AActor* ExtraTarget;
    ROGUECORE_API FLaserPointerTarget();
};
