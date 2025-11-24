#pragma once
#include "CoreMinimal.h"
#include "FSDFlyingBugController.h"
#include "DashingFlyingBugController.generated.h"

UCLASS(Blueprintable, NoExport)
class ADashingFlyingBugController : public AFSDFlyingBugController {
    GENERATED_BODY()
public:
    ADashingFlyingBugController(const FObjectInitializer& ObjectInitializer);
};
