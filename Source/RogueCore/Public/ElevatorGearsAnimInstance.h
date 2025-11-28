#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ElevatorGearsAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UElevatorGearsAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Velocity;
    
    float MoveSpeed;
    bool IsMoving;
    UElevatorGearsAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetIsMoving(bool Moving);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsMoving() const;
};
