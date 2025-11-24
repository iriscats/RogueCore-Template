#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnalogAimSettings.generated.h"

class UCurveFloat;
USTRUCT(BlueprintType)
struct FAnalogAimSettings {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AimRate;
    
    UCurveFloat* SensitivityCurve;
    float LookAtStickyness;
    float StickynessRecoverySpeed;
    float StickynessMaxSensitivity;
    FVector2D ThirdPersonLookRate;
    ROGUECORE_API FAnalogAimSettings();
};
