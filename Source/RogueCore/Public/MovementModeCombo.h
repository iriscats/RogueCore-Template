#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "EMovementCustomMode.h"
#include "MovementModeCombo.generated.h"

USTRUCT(BlueprintType)
struct FMovementModeCombo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> Mode;
    
    TEnumAsByte<EMovementCustomMode> CustomMode;
    ROGUECORE_API FMovementModeCombo();
};
