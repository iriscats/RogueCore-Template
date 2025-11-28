#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AmbientBlasterAnimInstance.generated.h"

class APlayerCharacter;
class UNiagaraComponent;
class UNiagaraSystem;
UCLASS(Blueprintable, NonTransient)
class UAmbientBlasterAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* RechargeParticle;
    
    FName RechargeParticleSocketName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* SpawnedRechargeParticle;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UAmbientBlasterAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SpawnRechargeParticle();
    void DestroyRechargeParticle();
};
