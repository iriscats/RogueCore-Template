#pragma once
#include "CoreMinimal.h"
#include "DownCameraSettings.generated.h"

class APlayerCharacter;
USTRUCT(BlueprintType)
struct FDownCameraSettings {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Target;

    int32 TargetIndex;
    ROGUECORE_API FDownCameraSettings();
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPitch;
    float MaxPitch;
    float SmoothSpeed;
};
