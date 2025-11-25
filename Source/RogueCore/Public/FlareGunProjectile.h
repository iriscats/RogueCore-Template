#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "FlareGunProjectile.generated.h"

class ATeamTransport;
UCLASS(Blueprintable)
class AFlareGunProjectile : public AProjectile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFlareOn, meta=(AllowPrivateAccess=true))
    bool IsFlareOn;
    AFlareGunProjectile(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateLightDuration(float lightDuration);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateShadowRadius();
    UFUNCTION()
    void OnRep_IsFlareOn();
    void OnFlareIgnite();
    void OnFlareExtinguish();
 
    void OnDroppodImpact(ATeamTransport* DropPod);
    void Inhibit();
    void ActivateFlare();
};
