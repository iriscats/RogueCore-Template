#pragma once
#include "CoreMinimal.h"
#include "EHackingPodState.h"
#include "HackingPod_DelegateDelegate.h"
#include "RessuplyPod.h"
#include "FacilityHackingPod.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API AFacilityHackingPod : public ARessuplyPod {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHackingPod_Delegate OnHackingPodStateChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PodState, meta=(AllowPrivateAccess=true))
    EHackingPodState PodState;

 
    AFacilityHackingPod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(EHackingPodState aState);
    UFUNCTION(BlueprintCallable)
    void OnRep_PodState(EHackingPodState oldState);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitState(EHackingPodState oldState);
    void OnEnterState(EHackingPodState NextState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHackingPodState GetState() const;
};
