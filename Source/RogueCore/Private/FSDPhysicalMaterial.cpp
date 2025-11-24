#include "FSDPhysicalMaterial.h"

UFSDPhysicalMaterial::UFSDPhysicalMaterial() {
    this->MaterialType = EPhysicalMaterialType::Any;
    this->BreakingDecelerationScale = 1.00f;
    this->BreakingFrictionScale = 1.00f;
    this->MaxAccelerationScale = 1.00f;
    this->RepulsePlayer = false;
    this->RepulsePlayerRandomDegreeOffset = 0.00f;
    this->RepulsePlayerSound = NULL;
    this->RepulsePlayerParticle = NULL;
    this->ImpactParticles = NULL;
    this->ImpactParticleScale = 1.00f;
    this->ImpactMaterialOverride = NULL;
    this->ImpactSound = NULL;
    this->ImpactSoundFPVolumeScale = 1.00f;
    this->ImpactSoundFPAttenuation = NULL;
    this->MeleeImpactSound = NULL;
    this->UseImpactDecalOverrides = false;
    this->ImpactDecals.AddDefaulted(3);
    this->FirstPersonDamageIndicatorSound = NULL;
    this->IsWeakPoint = false;
    this->IsSubhealthCollider = false;
    this->DamageMultiplier = 1.00f;
    this->FootStepParticle = NULL;
    this->FootstepMaterialOverride = NULL;
    this->FootStepSound = NULL;
    this->ExtraFallVelocity = 0.00f;
    this->FallImpactEffect = NULL;
    this->FallImpactSound = NULL;
    this->AlwaysPenetrate = false;
    this->OneSidedPenetrate = false;
    this->ReactiveTerrain = NULL;
}

UNiagaraComponent* UFSDPhysicalMaterial::SpawnImpactParticlesFromHit(UObject* WorldContextObject, const FHitResult& HitResult) {
    return NULL;
}

UNiagaraComponent* UFSDPhysicalMaterial::SpawnImpactParticles(UObject* WorldContextObject, FVector Location, FVector Normal, UElementType* ElementType) const {
    return NULL;
}

UFSDPhysicalMaterial* UFSDPhysicalMaterial::GetPhysicalMaterialFromPrimitive(UPrimitiveComponent* Component) {
    return NULL;
}


