#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "LockCountDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ULockCountDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinLockCount;
    
    bool UseTotalLockCount;
    ULockCountDamageCondition();
};
