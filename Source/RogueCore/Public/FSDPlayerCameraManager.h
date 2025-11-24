#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "FSDPlayerCameraManager.generated.h"

UCLASS(Blueprintable, MinimalAPI, NoExport, NonTransient)
class AFSDPlayerCameraManager : public APlayerCameraManager {
    GENERATED_BODY()
public:
    AFSDPlayerCameraManager(const FObjectInitializer& ObjectInitializer);
};
