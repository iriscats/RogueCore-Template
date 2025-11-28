#pragma once
#include "CoreMinimal.h"

#include "RejoinFloat.generated.h"

USTRUCT(BlueprintType)
struct FRejoinFloat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ItemKey;
    
    FName ValueKey;
    float Value;
    ROGUECORE_API FRejoinFloat();
};
