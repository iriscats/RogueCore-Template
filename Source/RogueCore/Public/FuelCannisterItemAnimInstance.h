#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FuelCannisterItemAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFuelCannisterItemAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsOnGround;
    
    bool IsFull;
    bool IsShooting;
    UFuelCannisterItemAnimInstance();
};
