#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ItemDispenserAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UItemDispenserAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsOpen;
    
    bool HasItem;
    UItemDispenserAnimInstance();
};
