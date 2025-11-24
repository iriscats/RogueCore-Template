#pragma once
#include "CoreMinimal.h"
#include "CellId.generated.h"

USTRUCT(BlueprintType)
struct ROGUECOREENGINE_API FCellId {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int16 X;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int16 Y;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int16 Z;
    
    FCellId();
};

