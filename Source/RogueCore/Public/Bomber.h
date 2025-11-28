#pragma once
#include "CoreMinimal.h"


#include "AFlyingBug.h"
#include "Templates/SubclassOf.h"
#include "Bomber.generated.h"

class AActor;
class AProjectile;
class UAudioComponent;
class UFXSystemAsset;
class UFXSystemComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USoundBase;
UCLASS(Blueprintable)
class ABomber : public AAFlyingBug {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* GooSoundComponent;
    
    UParticleSystemComponent* AcidEmitterLeft;
    UParticleSystemComponent* AcidEmitterRight;
    UNiagaraComponent* AcidEmitterLeftNS;
    UNiagaraComponent* AcidEmitterRightNS;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> AcidProjectile;
    UFXSystemAsset* deathParticles;
    USoundBase* deathSound;
    USoundBase* DeathPanicSound;
    UFXSystemAsset* BleedParticles;
    USoundBase* BladderDestroyedNoise;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UFXSystemComponent> BleedParticlesComponent;
    TWeakObjectPtr<UAudioComponent> PanicAudioComponent;
    float RagdollForceModifier;
    float DeathYRotationSpeed;
    float DeathXRotationSpeed;
    float SearchRange;
    float NewPointMax;
    float NewPointMin;
    float DeathSpeed;
    float DeathAcceleration;
    float AcidRate;
    float PostDeathAcidTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Death, meta=(AllowPrivateAccess=true))
    bool HasDied;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsRightDestroyed;
    bool IsLeftDestroyed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DropAcid, meta=(AllowPrivateAccess=true))
    bool dropAcid;
    bool NoDeathSpiral;
    ABomber(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopSpinAndDie();
    void SetDropAcid(bool NewDropAcid);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartDeathPanic();
    UFUNCTION()
    void OnRep_DropAcid();
    UFUNCTION()
    void OnRep_Death();
    void OnRagdollHitGround(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    void OnBladderDamage(float amount);
    void OnArmorDestroyed(FName Name);
    void HideMesh();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDropAcid() const;
    bool AreBladdersDestroyed() const;
};
