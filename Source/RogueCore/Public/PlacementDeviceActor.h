#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlacementDeviceActor.generated.h"

class UPawnStat;
UCLASS(Abstract, Blueprintable)
class APlacementDeviceActor : public AActor {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultRadius;
    
    UPawnStat* RadiusStat;
    float DefaultLifetime;
    UPawnStat* LifetimeStat;
    APlacementDeviceActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInstigatorChanged();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDeviceRadius() const;
    float GetDeviceLifetime() const;
};
