#pragma once
#include "CoreMinimal.h"
#include "EUnlockType.generated.h"

UENUM(BlueprintType)
enum class EUnlockType : uint8 {
    Upgrade,
    BioBooster,
    Artifact,
    AbilityUpgrade,
    Weapon,
    Equipment,
    Throwables,
    Grenades,
};
