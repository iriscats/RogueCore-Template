#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ECoreCrusherState.h"
#include "CoreCrusherAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UCoreCrusherAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECoreCrusherState CoreCrusherState;
    
    float BootingTimeLeft;
    UCoreCrusherAnimInstance();
};
