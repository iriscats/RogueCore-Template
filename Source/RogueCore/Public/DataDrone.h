#pragma once
#include "CoreMinimal.h"
#include "AFlyingBug.h"
#include "ActorDelegateDelegate.h"
#include "DataDrone.generated.h"

class USpinDeathComponent;
UCLASS(Blueprintable, NoExport)
class ADataDrone : public AAFlyingBug {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorDelegate OnDataDroneKilled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpinDeathComponent* SpinDeathComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsDataDroneFleeing, meta=(AllowPrivateAccess=true))
    bool IsDataDroneFleeing;
 
    ADataDrone(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnGuardDrones();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDataDroneIsFleeing(bool InFleeing);
    UFUNCTION(BlueprintCallable)
    void OnRep_IsDataDroneFleeing(bool oldFleeing);
    void OnFleeingChanged(bool NewFleeing);
    void BroadcastDataDroneKilled();
};
