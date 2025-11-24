#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "ScaledEffect.h"
#include "SpawnAtLocationParticleAfflictionEffect.generated.h"

UCLASS(Blueprintable)
class USpawnAtLocationParticleAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScaledEffect ScaledParticleEffect;
    
    USpawnAtLocationParticleAfflictionEffect();
};
