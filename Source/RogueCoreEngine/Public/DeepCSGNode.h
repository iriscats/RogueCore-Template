#pragma once
#include "CoreMinimal.h"
#include "DeepCSGNode.generated.h"

USTRUCT(BlueprintType)
struct FDeepCSGNode {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Val;
    
    ROGUECOREENGINE_API FDeepCSGNode();
};

