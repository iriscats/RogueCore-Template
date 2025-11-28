#pragma once
#include "CoreMinimal.h"
#include "ChargedWeapon.h"
#include "AmbientChargeBlaster.generated.h"

class UAnimMontage;
class UChargedProjectileLauncherComponent;
class UCurveFloat;
class UNiagaraSystem;
UCLASS(Blueprintable)
class AAmbientChargeBlaster : public AChargedWeapon {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeProgressForOtherFireAnim;

    UAnimMontage* OtherFireAnimFP;
    UAnimMontage* OtherFireAnimTP;
    UCurveFloat* ChargeRecoilCurve;
    UNiagaraSystem* MuzzleParticlesWeak;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChargedProjectileLauncherComponent* LauncherComponent;

 
    AAmbientChargeBlaster(const FObjectInitializer& ObjectInitializer);
};
