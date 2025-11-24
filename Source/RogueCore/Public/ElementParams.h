#pragma once
#include "CoreMinimal.h"
#include "ElementParams.generated.h"

USTRUCT(BlueprintType)
struct FElementParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElementMultiplier;
    
    bool ChangeElementValueAtMax;
    ROGUECORE_API FElementParams();
};
