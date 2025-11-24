#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnchorTurnerAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAnchorTurnerAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ModuleRotation;
    
    float Percent;
    float TurnSpeed;
    bool IsFinished;
    UAnchorTurnerAnimInstance();
};
