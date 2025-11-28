#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FuelCannisterAttachedAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFuelCannisterAttachedAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CanBeTaken;
    
    UFuelCannisterAttachedAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetCanBeTaken(bool canBeTakenValue);
};
