#pragma once
#include "CoreMinimal.h"

#include "AbilityItem.h"
#include "BeamItem.generated.h"

class UAnimMontage;
class UNiagaraComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ABeamItem : public AAbilityItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* FP_BeamEffect;
    
    UNiagaraComponent* TP_BeamEffect;
    UNiagaraComponent* ValidTargetImpactEffect;
    UNiagaraComponent* InvalidTargetImpactEffect;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* EndBeamAnim;
    float Interval;
    float CostInterval;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsBeamActive, meta=(AllowPrivateAccess=true))
    bool IsBeamActive;
    ABeamItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_SetBeamActive(bool IsActive);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_HitTarget(const FHitResult& Hit);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SecondaryUsed();
    void Receive_OnHitTarget(FHitResult Hit);
    UFUNCTION(BlueprintCallable)
    void OnRep_IsBeamActive();
    void OnBeamDeactivated();
    void OnBeamActivated();
};
