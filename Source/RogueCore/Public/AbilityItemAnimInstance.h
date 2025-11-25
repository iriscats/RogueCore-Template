#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AbilityItemAnimInstance.generated.h"

class AAbilityItem;
UCLASS(Blueprintable, NonTransient)
class UAbilityItemAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected sectio                      

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsEqupped;
    
    AAbilityItem* Item;
    UAbilityItemAnimInstance();
};
