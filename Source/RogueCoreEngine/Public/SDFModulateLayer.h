#pragma once
#include "CoreMinimal.h"
#include "SDFModulateLayer.generated.h"

USTRUCT(BlueprintType)
struct FSDFModulateLayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModulateDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SDFOffset;
    
    ROGUECOREENGINE_API FSDFModulateLayer();
};

