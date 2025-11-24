#pragma once
#include "CoreMinimal.h"
#include "BaseGymMinigame.h"
#include "RunGymMinigame.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URunGymMinigame : public UBaseGymMinigame {
    GENERATED_BODY()
public:
    URunGymMinigame(const FObjectInitializer& ObjectInitializer);
};
