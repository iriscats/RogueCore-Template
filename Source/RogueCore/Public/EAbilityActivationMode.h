#pragma once
#include "CoreMinimal.h"
#include "EAbilityActivationMode.generated.h"

UENUM(BlueprintType)
enum class EAbilityActivationMode : uint8 {
    Contextual,
    Toggle,
    Hold,
};
