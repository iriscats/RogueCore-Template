#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "CameraParticleAfflictionEffect.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable)
class UCameraParticleAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ParticleEffect;

    UCameraParticleAfflictionEffect();

};
