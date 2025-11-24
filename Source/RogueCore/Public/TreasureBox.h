#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EInputKeys.h"
#include "Templates/SubclassOf.h"
#include "TreasureContainer.h"
#include "TreasureBox.generated.h"

class AActor;
class APlayerCharacter;
class AProceduralSetup;
class UAnimSequenceBase;
class UCurveFloat;
class UDebrisPositioning;
class URepairableComponent;
class URepairableUsable;
class USingleUsableComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UTerrainPlacementComponent;
class UTreasureRewarder;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATreasureBox : public ATreasureContainer {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    int32 ItemsInserted;

    bool IsTreasureAvailable;

    ATreasureBox(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URepairableComponent* Repairable;
    
    URepairableUsable* RepairUsable;
    USingleUsableComponent* HammeringUsable;
    UTerrainPlacementComponent* terrainPlacement;
    UStaticMeshComponent* MiddlePlane;
    USkeletalMeshComponent* BoxMesh;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Batteries;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollectActivationDelay;
    UAnimSequenceBase* OpenBoxAnim;
    float DelayToOpenAfterRepair;
    TSubclassOf<AActor> ResourceClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTreasureRewarder* boxRewarder;
    float HologramRotationSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 ItemsInserted;
    bool IsTreasureAvailable;
    ATreasureBox(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void PlaceResources(AProceduralSetup* setup, float Radius, UDebrisPositioning* DebrisPositioning, const TArray<FVector>& LocationsToAvoid, UCurveFloat* AvoidCostCurve);
    void OnUsedEvent(APlayerCharacter* User, EInputKeys Key);
    void OnRepairedEvent(URepairableComponent* repaired);
    void OnHammerProgress(float Progress);
    void OnHammered(APlayerCharacter* User, EInputKeys Key);
    void OnFullyRepairedEvent(URepairableComponent* repaired);
    void OnAllResourcesCollectedEvent(URepairableComponent* repaired);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnCollectedTreasure(APlayerCharacter* collector);
    void AfterRepairDelay();
    void ActivateCollection();
};
