#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hackprogress_DelegateDelegate.h"
#include "FacilityPowerStation.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFacilityPowerStation : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsHacking, meta=(AllowPrivateAccess=true))

    bool IsHacking;

    AFacilityPowerStation(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHackprogress_Delegate OnHackingProgressDelegate;
    
    FHackprogress_Delegate OnProgresspointDelegate;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProgressPoint;
    int32 ProgresPointCount;
    float TimeToDefend;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Progress, meta=(AllowPrivateAccess=true))
    float Progress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsHacking, meta=(AllowPrivateAccess=true))
    bool IsHacking;
    AFacilityPowerStation(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopHacking();
    void StartHacking();
    UFUNCTION(BlueprintCallable)
    void OnRep_Progress();
    UFUNCTION()
    void OnRep_IsHacking();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHackingComplete();
    void OnHackingChanged(bool NewIsHacking);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHacked() const;
};
