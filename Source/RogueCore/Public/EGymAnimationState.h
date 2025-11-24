#pragma once
#include "CoreMinimal.h"
#include "EGymAnimationState.generated.h"

UENUM(BlueprintType)
enum class EGymAnimationState : uint8 {
    Start,
    GoingDown,
    IdleDown,
    GoingUp,
    IdleUp,
    UpFail,
    DownFail,
    End,
    None,
};
