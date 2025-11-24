#pragma once
#include "CoreMinimal.h"
#include "EFSDSoundParameter.generated.h"

UENUM(BlueprintType)
enum class EFSDSoundParameter : uint8 {
    IsLocalPlayer,
    TargetIsLocalPlayer,
};
