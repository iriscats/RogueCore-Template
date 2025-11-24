#pragma once
#include "CoreMinimal.h"
#include "EWeaponTagActivationType.generated.h"

UENUM(BlueprintType)
enum class EWeaponTagActivationType : uint8 {
    EOnHit,
    EOnKill,
    EOnCrit,
};
