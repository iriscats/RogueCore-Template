#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UnlockableWithCount.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FUnlockableWithCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ID;
    
    uint8 count;
    FUnlockableWithCount();
};
