#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState_TimedParticleEffect.h"
#include "AnimNotifyState_TimedParticleEffectWithImpactDecals.generated.h"

class UMaterialInterface;
class UPhysicalMaterial;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_TimedParticleEffectWithImpactDecals : public UAnimNotifyState_TimedParticleEffect {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DecalMaterial;
    
    float DecalSize;
    float FadeStartDelay;
    float FadeDuration;
    UAnimNotifyState_TimedParticleEffectWithImpactDecals();
    UFUNCTION(BlueprintCallable)
    void OnParticleCollision(FName EventName, float EmitterTime, int32 ParticleTime, FVector Location, FVector Velocity, FVector Direction, FVector Normal, FName BoneName, UPhysicalMaterial* PhysMat) const;
};
