#pragma once
#include "CoreMinimal.h"
#include "ProjectileWeapon.h"
#include "PlasmaCarbine.generated.h"

class UAnimMontage;
UCLASS(Abstract, Blueprintable)
class APlasmaCarbine : public AProjectileWeapon {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RateOfFireBoostOnFullShield;
    
    bool RemoveShieldOnOverheat;
    bool RemoveShieldOnReload;
    float HeatEffectsThreshold;
    UAnimMontage* FP_CharacterOverheatEndMontage;
    UAnimMontage* TP_CharacterOverheatEndMontage;
    UAnimMontage* WPN_ItemOverheatEndMontage;
    UAnimMontage* FP_CharacterReloadEndMontage;
    UAnimMontage* TP_CharacterReloadEndMontage;
    UAnimMontage* WPN_ItemReloadEndMontage;
    APlasmaCarbine(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ApplyShieldDamage();
};
