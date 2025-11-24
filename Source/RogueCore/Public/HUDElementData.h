#pragma once
#include "CoreMinimal.h"
#include "EHUDVisibilityMode.h"
#include "HUDElementData.generated.h"

USTRUCT(BlueprintType)
struct FHUDElementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDVisibilityMode Mode;
    
    int32 Version;
    ROGUECORE_API FHUDElementData();
};
