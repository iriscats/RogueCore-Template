#pragma once
#include "CoreMinimal.h"


#include "PhysicalMaterials/PhysicalMaterial.h"
#include "DecalData.h"
#include "EPhysicalMaterialType.h"
#include "SkeletalMeshDecalData.h"
#include "Templates/SubclassOf.h"
#include "FSDPhysicalMaterial.generated.h"

class UElementEventTypeBase;
class UElementType;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UMaterialInstance;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class UPrimitiveComponent;
class UReactiveTerrain;
class USoundAttenuation;
class USoundBase;
UCLASS(Blueprintable, CollapseCategories)
class ROGUECORE_API UFSDPhysicalMaterial : public UPhysicalMaterial {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhysicalMaterialType MaterialType;
    
    float BreakingDecelerationScale;
    float BreakingFrictionScale;
    float MaxAccelerationScale;
    bool RepulsePlayer;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval RepulsePlayerVelocity;
    float RepulsePlayerRandomDegreeOffset;
    USoundBase* RepulsePlayerSound;
    UFXSystemAsset* RepulsePlayerParticle;
 
    UNiagaraSystem* ImpactParticles;
    float ImpactParticleScale;
    UMaterialInstance* ImpactMaterialOverride;
    FLinearColor ImpactColorOverride;
    USoundBase* ImpactSound;
    float ImpactSoundFPVolumeScale;
    USoundAttenuation* ImpactSoundFPAttenuation;
    USoundBase* MeleeImpactSound;
    bool UseImpactDecalOverrides;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FDecalData> ImpactDecals;
    FSkeletalMeshDecalData SkeletalMeshDecal;
    USoundBase* FirstPersonDamageIndicatorSound;
    bool IsWeakPoint;
    bool IsSubhealthCollider;
    float DamageMultiplier;
    UFXSystemAsset* FootStepParticle;
    UMaterialInstance* FootstepMaterialOverride;
    FDecalData LeftFootprintDecal;
    FDecalData RightFootprintDecal;
    USoundBase* FootStepSound;
    float ExtraFallVelocity;
    UFXSystemAsset* FallImpactEffect;
    USoundBase* FallImpactSound;
    bool AlwaysPenetrate;
    bool OneSidedPenetrate;
    TSubclassOf<UReactiveTerrain> ReactiveTerrain;
    TSet<TSubclassOf<UElementEventTypeBase>> AllowedElementEventBonus;
    UFSDPhysicalMaterial();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UNiagaraComponent* SpawnImpactParticlesFromHit(UObject* WorldContextObject, const FHitResult& HitResult);
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
    UNiagaraComponent* SpawnImpactParticles(UObject* WorldContextObject, FVector Location, FVector Normal, UElementType* ElementType) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UFSDPhysicalMaterial* GetPhysicalMaterialFromPrimitive(UPrimitiveComponent* Component);
};
