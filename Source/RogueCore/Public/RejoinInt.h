#pragma once
#include "CoreMinimal.h"

#include "RejoinInt.generated.h"

USTRUCT(BlueprintType)
struct FRejoinInt {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ItemKey;
    
    FName ValueKey;
    int32 Value;
    ROGUECORE_API FRejoinInt();
};
