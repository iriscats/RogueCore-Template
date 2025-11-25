#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "RepairObjective.generated.h"

class AActor;
class UDebrisPositioning;
class UGemResourceData;
class URepairableComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URepairObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RepairedObjectives, meta=(AllowPrivateAccess=true))
    int32 RepairedObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ObjectivesToRepair, meta=(AllowPrivateAccess=true))
    int32 ObjectivesToRepair;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> RepairObjectiveClass;
    UGemResourceData* RepairObjectiveResource;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    int32 RepairResourcesPerActor;
    float RepairResourceDistanceFromActor;
    float MinRepairObjectiveDistanceToLandingZone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RepairedObjectivesList;
    bool UseBXEChunks;
    URepairObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_RepairedObjectives();
    UFUNCTION()
    void OnRep_ObjectivesToRepair();
    void OnObjectiveRepaired(URepairableComponent* Repairable);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AllObjectivesRepaired();
};
