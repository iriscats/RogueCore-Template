#pragma once
#include "CoreMinimal.h"
#include "RandIntegerValue.generated.h"

USTRUCT(BlueprintType)
struct FRandIntegerValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    float Weight;
    ROGUECORE_API FRandIntegerValue();
};
