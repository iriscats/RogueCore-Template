#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestAnimInstanceProxy.h"
#include "TestAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTestAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTestAnimInstanceProxy AnimInstanceProxy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkCycleSpeed;
    float StartMovingSpeed;
    float StopMovingSpeed;
    float WalkCycleMinRate;
    float MeshScale;
    UTestAnimInstance();
};
