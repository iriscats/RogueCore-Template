#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "ChargedProjectile.generated.h"

UCLASS(Blueprintable, NoExport)
class AChargedProjectile : public AProjectile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool ExplodesWhenDead;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool PersistentExplosion;
protected:
    bool AoEDamageInFlight;
    float DirectDamageReduction;
    AChargedProjectile(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAoEDamageEnabled();
};
