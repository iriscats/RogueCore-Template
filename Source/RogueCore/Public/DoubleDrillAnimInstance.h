#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DoubleDrillAnimInstance.generated.h"

class ADoubleDrillItem;
UCLASS(Blueprintable, NonTransient)
class UDoubleDrillAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DrillSpeed;
    
    bool IsMining;
    bool IsGunslinging;
    ADoubleDrillItem* Item;
    UDoubleDrillAnimInstance();
};
