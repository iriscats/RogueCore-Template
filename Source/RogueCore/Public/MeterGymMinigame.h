#pragma once
#include "CoreMinimal.h"
#include "BaseGymMinigame.h"
#include "MeterGymMinigame.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMeterGymMinigame : public UBaseGymMinigame {
    GENERATED_BODY()
public:
    UMeterGymMinigame(const FObjectInitializer& ObjectInitializer);
};
