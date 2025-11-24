#pragma once
#include "CoreMinimal.h"
#include "BaseGymMinigame.h"
#include "UButtonGymMinigame.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUButtonGymMinigame : public UBaseGymMinigame {
    GENERATED_BODY()
public:
    UUButtonGymMinigame(const FObjectInitializer& ObjectInitializer);
};
