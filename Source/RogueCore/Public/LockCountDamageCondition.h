#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "LockCountDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ULockCountDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinLockCount;
    
    bool UseTotalLockCount;
    ULockCountDamageCondition();
};
