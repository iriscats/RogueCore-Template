#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CorespawnRift.generated.h"

UCLASS(Blueprintable)
class ACorespawnRift : public AActor {
    GENERATED_BODY()
public:
    ACorespawnRift(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRiftEnabled();
    
    void OnRiftDisabled();
    UFUNCTION(BlueprintCallable)
    void EnableRift();
    void DisableRift();
};
