#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/NetSerialization.h"
#include "MineHitEventDelegate.h"
#include "DroneMiningToolBase.generated.h"

class UTerrainMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneMiningToolBase : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMineHitEvent HitSomething;
    
 
    float Range;
    float SameHitDistance;
    float MineRadius;
    int32 MineStrength;
    UDroneMiningToolBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopMining();
    void StartMining();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void SpawnEffects(UTerrainMaterial* aTerrainMaterial, bool aParialHit, FVector_NetQuantize aLocation, FVector_NetQuantize aImpactNormal);
};
