#pragma once
#include "CoreMinimal.h"
#include "ActionIconMapping.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FActionIconMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKey ActionKey;
    
    UTexture2D* Icon;
    bool DoNotTint;
    ROGUECORE_API FActionIconMapping();
};
