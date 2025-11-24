#pragma once
#include "CoreMinimal.h"
#include "DroneControllerBase.h"
#include "StateDrivenDroneController.generated.h"

UCLASS(Blueprintable, NoExport)
class AStateDrivenDroneController : public ADroneControllerBase {
    GENERATED_BODY()
public:
    AStateDrivenDroneController(const FObjectInitializer& ObjectInitializer);
};
