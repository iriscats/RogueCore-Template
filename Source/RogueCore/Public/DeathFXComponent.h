#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/NetSerialization.h"
#include "DamageData.h"
#include "DeathTypeData.h"
#include "DeathTypedDelegate.h"
#include "Templates/SubclassOf.h"
#include "DeathFXComponent.generated.h"

class AEnemyDeepPathfinderCharacter;
class AFSDPawn;
class UCameraShakeBase;
class UDamageTag;
class UHealthComponent;
class ULimbDismembermentList;
class UMaterialInstance;
class UNiagaraSystem;
class UPhysicsAsset;
class USkeletalMeshComponent;
class USoundAttenuation;
class USoundClass;
class USoundCue;
class USpiderAnimInstance;
class UStaticMesh;
class UStaticMeshComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDeathFXComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeathTyped OnDeathTyped;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> CrossbowChemicalExplosionStatusEffect;
    TSubclassOf<UStatusEffect> PlasmaExplosionStatusEffect;
    TSubclassOf<UStatusEffect> PlasmaExplosionDOTStatusEffect;
    UNiagaraSystem* GibParticles;
    UStaticMesh* GoreMesh;
    FName HeadGoreMeshAttachSocket;
    TArray<FName> HeadGoreBoneNames;
    UNiagaraSystem* HeadshotParticles;
    FName HeadshotFXSocket;
    UNiagaraSystem* deathParticles;
    UMaterialInstance* DeathMaterialOverride;
    FLinearColor DeathColorOverride;
    UNiagaraSystem* BloodSquirtParticles;
    UNiagaraSystem* BurnDeathParticles;
    UNiagaraSystem* FrozenDeathParticles;
    UNiagaraSystem* CorrosiveDeathParticles;
    UNiagaraSystem* CookedDeathParticles;
    UNiagaraSystem* ChemicalExplosionDeathParticles;
    UMaterialInstance* DeathSplatDecal;
    float DeathSplatDecalSize;
    USoundClass* NotLocalInstigator_SoundClassOverride;
    USoundAttenuation* NotLocalInstigator_SoundAttenuationOverride;
    USoundCue* deathSound;
    USoundCue* HeadshotGibsSound;
    USoundCue* BurnDeathSound;
    USoundCue* CorrosiveDeathSound;
    USoundCue* CookedDeathSound;
    USoundCue* ChemicalExplosionPreDeathSound;
    USoundCue* ChemicalExplosionDeathSound;
    USoundCue* DeathSplatSound;
    float DissolveDelay;
    UMaterialInstance* DissolveBaseShader;
    UMaterialInstance* BurnBaseShader;
    UMaterialInstance* CorrosiveBaseShader;
    FLinearColor BurnColor;
    bool RagdollEnabled;
    UPhysicsAsset* RagdollPhysicsAsset;
    TSubclassOf<UCameraShakeBase> CameraShake;
    float DeathDuration;
    float PostBurnRagdollDelay;
    ULimbDismembermentList* LimbDismembermentList;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DeathType, meta=(AllowPrivateAccess=true))
    FDeathTypeData DeathType;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HeadGoreMesh;
    USkeletalMeshComponent* SkeletalMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDPawn* FSDPawn;
    AEnemyDeepPathfinderCharacter* PFCharacter;
    USpiderAnimInstance* AnimInstance;
    UDeathFXComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_DeathType();
    void OnDeathDetailed(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& Tags);
    UStaticMeshComponent* CreateHeadGore();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void AllRagdoll(const FVector_NetQuantize& Impulse, const FVector_NetQuantize& Location, int32 BoneIndex);
};
