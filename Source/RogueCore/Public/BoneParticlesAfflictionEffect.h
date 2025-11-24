#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "BoneParticlesAfflictionEffect.generated.h"

class UNiagaraSystem;
class USoundCue;
UCLASS(Abstract, Blueprintable)
class UBoneParticlesAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraSystem*> Particles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* Sound;
    UBoneParticlesAfflictionEffect();
};
