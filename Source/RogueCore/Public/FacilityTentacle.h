#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EFacilityTentacleState.h"
#include "TentacleBase.h"
#include "TentacleTarget.h"
#include "TriggerAI.h"
#include "FacilityTentacle.generated.h"

class UAnimMontage;
class UDebrisPositioning;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFacilityTentacle : public ATentacleBase, public ITriggerAI {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DesiredTarget, meta=(AllowPrivateAccess=true))

    FTentacleTarget DesiredTarget;

    AFacilityTentacle(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwaySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Extended;
    TArray<UAnimMontage*> HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TentacleState, meta=(AllowPrivateAccess=true))
    EFacilityTentacleState TentacleState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* HeadMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DesiredTarget, meta=(AllowPrivateAccess=true))
    FTentacleTarget DesiredTarget;
    AFacilityTentacle(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void PlayHitReaction(float amount);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChanged(EFacilityTentacleState NewState);
    UFUNCTION()
    void OnRep_TentacleState();
    UFUNCTION()
    void OnRep_DesiredTarget();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool FindBurrowLocation(UDebrisPositioning* Debris, const FVector& Origin, float Radius, FVector& OutLocation);
    // Fix for true pure virtual functions not being implemented
};
