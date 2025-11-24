#pragma once
#include "CoreMinimal.h"
#include "AnimationWeight.generated.h"

class UAnimMontage;
USTRUCT(BlueprintType)
struct FAnimationWeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Montage;
    
    float Frequency;
    float CoolDown;
    float OccurenceBonusInterval;
    int32 Index;
    ROGUECORE_API FAnimationWeight();
};
