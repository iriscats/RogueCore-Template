#pragma once
#include "CoreMinimal.h"
#include "ESpawnActorSpawnLocation.generated.h"

UENUM(BlueprintType)
enum class ESpawnActorSpawnLocation : uint8 {
    ETarget,
    EOwner,
    EOrigin,
};
