#pragma once
#include "CoreMinimal.h"
#include "Curves/RichCurve.h"
#include "WeakpointTask.generated.h"

USTRUCT(BlueprintType)
struct FWeakpointTask {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRichCurve GrowCurve;
    
    FRichCurve FadeCurve;
    ROGUECORE_API FWeakpointTask();
};
