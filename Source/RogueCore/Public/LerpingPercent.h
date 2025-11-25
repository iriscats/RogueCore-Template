#pragma once
#include "CoreMinimal.h"
#include "LerpingPercent.generated.h"

USTRUCT(BlueprintType)
struct FLerpingPercent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 TargetPercent;

    ROGUECORE_API FLerpingPercent();
 
};
