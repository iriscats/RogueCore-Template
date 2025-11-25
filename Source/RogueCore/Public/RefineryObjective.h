#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ERefineryState.h"
#include "Objective.h"
#include "Templates/SubclassOf.h"
#include "RefineryObjective.generated.h"

class AActor;
class AFSDRefinery;
class AProceduralSetup;
class UDebrisPositioning;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API URefineryObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryDelegate, AFSDRefinery*, InRefinery);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRefineryDelegate OnRefinerySpawned;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AFSDRefinery> refineryClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Refinery, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFSDRefinery> Refinery;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ERefineryState RefineryState;
    UDebrisPositioning* RefineryPlacement;
    TSoftClassPtr<AActor> RawMaterialClass;
    UDebrisPositioning* RawMaterialPlacement;
    int32 RawMaterialCount;
    bool bMissionCompleted;
    bool bIsFinalBattle;
    int32 OptionalTunnelRoomID;
    URefineryObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SpawnWells(AProceduralSetup* setup, const FVector& rigLocation, float minDistanceBetween, const TArray<FVector2D>& minMaxDistancesToRig);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRefinerySpawned(AFSDRefinery* InRefinery);
    UFUNCTION()
    void OnRep_Refinery();
    void OnRefineryStateChanged(ERefineryState InRefineryState);
    FVector GetRefinerySpawnLocation(TSubclassOf<AFSDRefinery> NewRefineryClass);
    void AddMissionCriticalItems(AProceduralSetup* setup);
};
