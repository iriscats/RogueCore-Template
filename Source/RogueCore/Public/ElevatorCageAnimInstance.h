#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ElevatorCageAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UElevatorCageAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CageOpen;
    
    UElevatorCageAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetIsOpen(bool Open);
};
