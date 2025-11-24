#pragma once
#include "CoreMinimal.h"
#include "EAbilityAmountType.generated.h"

UENUM(BlueprintType)
enum class EAbilityAmountType : uint8 {
    Damage,
    Size,
    Lifetime,
};
