#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlacementDeviceActor.generated.h"

class UPawnStat;
UCLASS(Abstract, Blueprintable, NoExport)
class APlacementDeviceActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
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
