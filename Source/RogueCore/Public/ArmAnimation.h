#pragma once
#include "CoreMinimal.h"
#include "ArmAnimation.generated.h"

class UAnimMontage;
USTRUCT(BlueprintType)
struct FArmAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Montage;
    
    int32 Index;
    int32 Arm;
    ROGUECORE_API FArmAnimation();
};
