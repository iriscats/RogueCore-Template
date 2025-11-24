#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ERefineryState.h"
#include "FSDRefineryAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFSDRefineryAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ERefineryState RefineryState;
    
    UFSDRefineryAnimInstance();
};
