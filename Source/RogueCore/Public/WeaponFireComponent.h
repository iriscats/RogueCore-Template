#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/NetSerialization.h"
#include "SpreadChangedDelegateDelegate.h"
#include "Upgradable.h"
#include "WeaponFireEndedDelegateDelegate.h"
#include "WeaponFiredDelegateDelegate.h"
#include "WeaponRicochetDelegateDelegate.h"
#include "WeaponFireComponent.generated.h"

class IWeaponFireOwner;
class UWeaponFireOwner;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponFireComponent : public UActorComponent, public IUpgradable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponFiredDelegate OnWeaponFired;
    
    FWeaponFireEndedDelegate OnWeaponFireEnded;
    FWeaponRicochetDelegate OnRicochetEvent;
    FSpreadChangedDelegate OnSpreadChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpreadCurve;
    float MinSpreadWhenMoving;
    float MinSpreadWhenSprinting;
    float MinSpread;
    float MaxSpread;
    float VerticalSpreadMultiplier;
    float HorizontalSpredMultiplier;
    float MaxVerticalSpread;
    float MaxHorizontalSpread;
    float SpreadRecoveryPerSecond;
    float SpreadPerShot;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TScriptInterface<IWeaponFireOwner> Weapon;
    bool UseDynamicSpread;
    UWeaponFireComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopFire();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetShotPower(float shotPower);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentVerticalSpread() const;
    float GetCurrentHorizontalSpread() const;
    void Fire(const FVector& Origin, const FVector_NetQuantizeNormal& Direction, bool playFireFX);
    // Fix for true pure virtual functions not being implemented
};
