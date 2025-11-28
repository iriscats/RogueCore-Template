#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "CameraParticleAfflictionEffect.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable)
class UCameraParticleAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ParticleEffect;

    UCameraParticleAfflictionEffect();

};
