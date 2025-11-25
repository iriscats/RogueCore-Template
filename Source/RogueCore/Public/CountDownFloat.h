#pragma once
#include "CoreMinimal.h"
#include "CountDownFloat.generated.h"

USTRUCT(BlueprintType)
struct FCountDownFloat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CountDownDuration;

    ROGUECORE_API FCountDownFloat();
 
};
