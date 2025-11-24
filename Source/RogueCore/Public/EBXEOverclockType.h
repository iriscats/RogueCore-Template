#pragma once
#include "CoreMinimal.h"
#include "EBXEOverclockType.generated.h"

UENUM()
enum class EBXEOverclockType : int32 {
    None,
    Safe,
    Any,
};
