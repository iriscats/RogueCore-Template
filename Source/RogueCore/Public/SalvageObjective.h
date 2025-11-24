#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DelegateDelegate.h"
#include "Objective.h"
#include "Templates/SubclassOf.h"
#include "SalvageObjective.generated.h"

class AActor;
class ADropPod;
class AMiniMule;
class AProceduralSetup;
class UCurveFloat;
class UDebrisBase;
class UDebrisPositioning;
class UGemResourceData;
class URepairableComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USalvageObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SalvageActorCount;
    
    UGemResourceData* LegResource;
    int32 LegCountPerActor;
    float LegDistanceToActor;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnDisableLegSpheres;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    TArray<TSoftObjectPtr<UDebrisBase>> Debris;
    TSoftClassPtr<AMiniMule> SalvageActor;
    TSoftClassPtr<ADropPod> DamagedPodClass;
    UDebrisPositioning* DamagedPodPositioning;
    float DamagedPodMinDistanceToDropZone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADropPod* DamagedPod;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActorsToSalvage, meta=(AllowPrivateAccess=true))
    int32 ActorsToSalvage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActorsSalvaged, meta=(AllowPrivateAccess=true))
    int32 ActorsSalvaged;
    int32 RepairPoints;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PointsRepaired, meta=(AllowPrivateAccess=true))
    int32 PointsRepaired;
    float MinSalvageActorDistanceToLandingZone;
    bool HasMuleReturnedToPod;
    TArray<AMiniMule*> AllSalvageActors;
    TArray<AMiniMule*> SalvagedActors;
    USalvageObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PointRepaired();
    UFUNCTION(BlueprintCallable)
    void OnRep_PointsRepaired();
    UFUNCTION()
    void OnRep_ActorsToSalvage(int32 prevAmount);
    UFUNCTION()
    void OnRep_ActorsSalvaged(int32 prevAmount);
    void OnActorRepaired(URepairableComponent* Repairable);
    static FTransform FindRepairPointLocation(AProceduralSetup* setup, const FVector& podLocation, float Radius, float maxVerticalDistance, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, const TArray<FVector>& LocationsToAvoid, UCurveFloat* AvoidCostCurve);
    static FTransform FindDamagedMiningPodLocation(AProceduralSetup* setup, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, float blockDistFromLandingZone);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AllActorsSalvaged();
};
