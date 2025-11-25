#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityItem.h"
#include "WeaponFireOwner.h"
#include "DartLauncher.generated.h"

class APlayerCharacter;
class UAnimMontage;
class UNiagaraSystem;
class UProjectileLauncherComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ADartLauncher : public AAbilityItem, public IWeaponFireOwner {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* projectileLauncher;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* MuzzleEffect;
    UAnimMontage* FP_FireAnimation;
    UAnimMontage* TP_FireAnimation;
    float DeactivationTime;
    float FireRate;
 
    ADartLauncher(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ShowFire();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowFire();
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
