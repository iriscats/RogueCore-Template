#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "EAfflictionSocket.h"
#include "AttachedParticlesAfflictionEffect.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable)
class UAttachedParticlesAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ParticleEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraSystem*> ParticleEffects;
    EAfflictionSocket Socket;
    bool ScaleToActor;
    bool UseVisibilityHack;
    bool UseBoneFilter;
    UAttachedParticlesAfflictionEffect();
};
