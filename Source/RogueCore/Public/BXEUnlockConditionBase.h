#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BXEUnlockConditionBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UBXEUnlockConditionBase : public UObject {
    GENERATED_BODY()
    
public:
    UBXEUnlockConditionBase();
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertResult;
};
