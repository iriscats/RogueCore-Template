#pragma once
#include "CoreMinimal.h"
#include "ETagBonus.generated.h"

UENUM(BlueprintType)
enum class ETagBonus : uint8 {
    EDamage,
    EDamageMultiplier,
    EWeakPointMultiplier,
    CriticalChance,
    ReloadSpeedMultiplier,
    EmptyReloadSpeedMultiplier,
    CapacityMultiplier,
    MagazineMultiplier,
};
