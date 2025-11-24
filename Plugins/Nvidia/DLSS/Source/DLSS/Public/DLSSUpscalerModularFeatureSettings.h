#pragma once
#include "CoreMinimal.h"
#include "EDLSSUpscalerModularFeatureQuality.h"
#include "DLSSUpscalerModularFeatureSettings.generated.h"

USTRUCT(BlueprintType)
struct DLSS_API FDLSSUpscalerModularFeatureSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDLSSUpscalerModularFeatureQuality Quality;
    
    FDLSSUpscalerModularFeatureSettings();
};

