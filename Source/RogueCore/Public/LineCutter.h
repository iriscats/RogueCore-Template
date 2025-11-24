#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "LineCutter.generated.h"

class ALineCutterProjectile;
class AProjectileBase;
class UItemUpgrade;
class UProjectileLauncherComponent;
UCLASS(Blueprintable, NoExport)
class ALineCutter : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UProjectileLauncherComponent* LauncherComponent;

    ALineCutter(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopUsingReversesProjectile;
    
    bool RotateProjectileUntillStop;
    bool ExplodeLastProjectileOnNextFireAttempt;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> upgrades;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LastProjectile, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALineCutterProjectile> LastProjectile;
    float MinExplosiveGoodbyeActivationTimme;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* LauncherComponent;
    ALineCutter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_StopRotatingProjectile_Implementation();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_ReverseLastProjectile_Implementation();
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void Server_DestroyOldProjectile();
    UFUNCTION(BlueprintCallable)
    void OnRep_LastProjectile() const;
    void OnProjectileLaunched(AProjectileBase* Projectile);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFireWhileLastProjectileAlive(ALineCutterProjectile* Projectile);
};
