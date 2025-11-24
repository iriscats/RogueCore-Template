#pragma once
#include "CoreMinimal.h"
#include "EBasicPanelType.generated.h"

UENUM(BlueprintType)
enum class EBasicPanelType : uint8 {
    Overlay,
    Horizontal,
    Vertical,
};

