#pragma once
#include "CoreMinimal.h"
#include "IKStyle.generated.h"

class UAnimSequence;
USTRUCT(BlueprintType)
struct FIKStyle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepAirTime;
    
    float StepRadius;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* RandomWalkCycles[6];
    UAnimSequence* NeutralAnimation;
    ROGUECORE_API FIKStyle();
};
