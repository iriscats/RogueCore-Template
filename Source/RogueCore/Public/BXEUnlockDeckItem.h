#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockDeckItem.generated.h"

class UBXEUnlockBase;
USTRUCT(BlueprintType)
struct FBXEUnlockDeckItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEUnlockBase* Unlock;
    
    float amount;
    ROGUECORE_API FBXEUnlockDeckItem();
};
