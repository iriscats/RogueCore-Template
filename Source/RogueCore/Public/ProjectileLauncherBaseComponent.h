#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "WeaponFireComponent.h"
#include "ProjectileLauncherBaseComponent.generated.h"

class AProjectileBase;
class UItemUpgrade;
class UPawnStatsComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileLauncherBaseComponent : public UWeaponFireComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProjectileSpawned, AProjectileBase*, Projectile);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreCollisionWithSelf;
    bool UseProjectileUpgrades;
    bool UseSpread;
    float VerticalSpread;
    float HorizontalSpread;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileSpawned OnProjectileSpawned;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> ProjectileUpgrades;
    float ArcStartAngle;
    bool TransferCharacterVelocityToProjectile;
    bool CameraToMuzzleFireCheck;
    UProjectileLauncherBaseComponent(const FObjectInitializer& ObjectInitializer);
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPawnStatsComponent> OwnerPawnStat;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StopFire();
    void Server_Fire(FVector Origin, FVector_NetQuantizeNormal Direction, FVector_NetQuantizeNormal initialBonusVelocity, AProjectileBase* DormentProjectile, bool notifyClients);
    UFUNCTION(BlueprintCallable)
    void OnWeaponRemovedFromStorage();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit();
};
