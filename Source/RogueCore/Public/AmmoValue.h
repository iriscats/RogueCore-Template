#pragma once
#include "CoreMinimal.h"
#include "AmmoValue.generated.h"

USTRUCT(BlueprintType)
struct FAmmoValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;

    ROGUECORE_API FAmmoValue();
};
