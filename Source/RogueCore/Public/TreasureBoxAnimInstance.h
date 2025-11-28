#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TreasureBoxAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTreasureBoxAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float BuildProgress;
    
    float PhysicsAlpha;
    bool IsTreasureAvailable;
    bool IsLeftInserted;
    bool IsRightInserted;
    UTreasureBoxAnimInstance();
};
