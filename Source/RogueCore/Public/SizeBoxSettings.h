#pragma once
#include "CoreMinimal.h"
#include "SizeBoxSettings.generated.h"

USTRUCT(BlueprintType)
struct FSizeBoxSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WidthOverride;
    
    float HeightOverride;
    float MinDesiredWidth;
    float MinDesiredHeight;
    float MaxDesiredWidth;
    float MaxDesiredHeight;
    float MinAspectRatio;
    float MaxAspectRatio;
    ROGUECORE_API FSizeBoxSettings();
};
