#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "ExplosionBaseComponent.h"
#include "ScaledEffect.h"
#include "ProjectileExplosion.generated.h"

class UForceFeedbackAttenuation;
class UForceFeedbackEffect;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileExplosion : public UExplosionBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayImpactFXFromMaterial;
    
    FScaledEffect ExplosionEffect;
    USoundCue* ExplosionSound;
    UForceFeedbackEffect* ForceFeedbackEffect;
    UForceFeedbackAttenuation* ForceFeedbackAttanuation;
    UProjectileExplosion(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnEffectsFromHit(const FHitResult& Hit);
    void SpawnEffects(FVector Location, FVector Normal);
};
