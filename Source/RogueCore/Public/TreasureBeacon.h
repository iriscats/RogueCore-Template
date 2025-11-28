#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTrackingCheatInterface.h"
#include "Templates/SubclassOf.h"
#include "TreasureBeacon.generated.h"

class ATreasureContainer;
class UCurveFloat;
class UDebrisPositioning;
class USceneComponent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ATreasureBeacon : public AActor, public IActorTrackingCheatInterface {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootComp;
    
    UTerrainPlacementComponent* terrainPlacement;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* TreasurePositioning;
    UDebrisPositioning* DebrisPartsPositioning;
    UCurveFloat* AvoidCostCurve;
    UCurveFloat* AvoidCostCurveDebris;
    float MaxRange;
    float MinRange;
    float DebrisSpawnRange;
    TSubclassOf<AActor> DebrisPartClass;
    int32 DebrisPartsToSpawn;
    int32 MaxSpawnLocationTries;
    TSubclassOf<ATreasureContainer> TreasureClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ATreasureContainer* TreasureInstance;
    ATreasureBeacon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SpawnDebreeParts() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ActivateTreasure();
    // Fix for true pure virtual functions not being implemented
};
