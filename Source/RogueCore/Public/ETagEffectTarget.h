#pragma once
#include "CoreMinimal.h"
#include "ETagEffectTarget.generated.h"

UENUM(BlueprintType)
enum class ETagEffectTarget : uint8 {
    EOwner,
    ETarget,
};
