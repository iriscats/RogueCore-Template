#pragma once
#include "CoreMinimal.h"

#include "CannisterRegisteredDelegate.h"
#include "EEscortMissionState.h"
#include "MuleRefueledDelegate.h"
#include "Objective.h"
#include "ShellBreakPauseChangeSignatureDelegate.h"
#include "ShellBreakTimerSignatureDelegate.h"
#include "EscortObjective.generated.h"

class AActor;
class AEscortDestination;
class AEscortMule;
class AExtractorItem;
class UCappedResource;
class UCarvedResourceData;
class UCurveFloat;
class UDebrisBase;
class UDebrisPositioning;
class UHealthComponentBase;
class UResourceData;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEscortObjective : public UObjective {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShellBreakTimerSignature OnProgressUpdated;
    
    FShellBreakPauseChangeSignature OnShellBreakPauseChange;
    FMuleRefueled OnMuleRefueled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DidRescueDorettaHead;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AreasToScan, meta=(AllowPrivateAccess=true))
    int32 AreasToScan;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ScanCount;
    TArray<FVector> ScanLocations;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    UDebrisPositioning* EscortMulePositioning;
    UCurveFloat* CostDistanceCurve;
    float DebrisRadius;
    TArray<UDebrisBase*> ObjectDebris;
    TSoftClassPtr<AActor> RefuelObjectClass;
    TSoftClassPtr<AEscortDestination> DestinationClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AreasScanned, meta=(AllowPrivateAccess=true))
    int32 AreasScanned;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EscortState, meta=(AllowPrivateAccess=true))
    EEscortMissionState State;
    bool FinalBattle;
    UCarvedResourceData* FuelResource;
    UResourceData* GemResource;
    FCannisterRegistered OnCannisterRegistered;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float ServerShellProgress;
    int32 SecondsToDestroyHeartstone;
    int32 FullCanistersRequired;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FullCanisters, meta=(AllowPrivateAccess=true))
    int32 FullCanisters;
    int32 FuelResourceAmount;
    TSoftClassPtr<AActor> GarageDropCarver;
    TSoftClassPtr<AActor> EscortMuleDropBeaconClass;
    TSoftClassPtr<AActor> GarageClass;
    FVector EscortMuleDropLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EscortMule, meta=(AllowPrivateAccess=true))
    AEscortMule* EscortMule;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AEscortDestination* EscortDestination;
    UEscortObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SyncProgressTimer();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StartShellBreak();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnGarage();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(EEscortMissionState NewState);
    void SetShellBreakPaused(bool newPaused);
    void SetEscortMule(AEscortMule* MULE);
    void RegisterFuelCannister(AExtractorItem* extractor);
    void RecordFailStage(bool muleDied, bool missionAborted);
    void OnResourceChanged(UCappedResource* CappedResource, float amount);
    UFUNCTION()
    void OnRep_FullCanisters();
    UFUNCTION()
    void OnRep_EscortState();
    UFUNCTION()
    void OnRep_EscortMule();
    UFUNCTION()
    void OnRep_AreasToScan(int32 prevAmount);
    UFUNCTION()
    void OnRep_AreasScanned(int32 prevAmount);
    void OnMuleDied(UHealthComponentBase* HealthComponent);
    void OnHealthChanged(float Health);
    void OnFullCanistersChanged(int32 amount);
    void OnEscortMuleSpawnedEvent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetShellBreakProgress();
    bool DoesPathExist(FVector Start, FVector End);
};
