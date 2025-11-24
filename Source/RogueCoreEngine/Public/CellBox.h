#pragma once
#include "CoreMinimal.h"
#include "CellId.h"
#include "CellBox.generated.h"

USTRUCT(BlueprintType)
struct FCellBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCellId min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCellId max;
    
    ROGUECOREENGINE_API FCellBox();
};

