#pragma once
#include "CoreMinimal.h"
#include "EThrownGrenadeItemState.generated.h"

UENUM()
enum class EThrownGrenadeItemState : int32 {
    NotEquipped,
    Equipped,
    Cooking,
    Throwing,
    WaitingToReturn,
};
