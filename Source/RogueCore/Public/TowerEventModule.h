#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventParticipant.h"
#include "FSDPawn.h"
#include "TowerEventModule.generated.h"

class ATowerEventModule;
class UArmorHealthDamageComponent;
class UEnemyHealthComponent;
class UFXSystemAsset;
class UParticleSystemComponent;
class USceneComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMesh;
class UStaticMeshComponent;
class UWeakpointGlowComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATowerEventModule : public AFSDPawn, public IEventParticipant {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    ATowerEventModule* PreviousModule;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    TArray<UStaticMeshComponent*> ArmorMeshes;

    ATowerEventModule(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* mesh;
    UEnemyHealthComponent* Health;
    UArmorHealthDamageComponent* ArmorDamage;
    UWeakpointGlowComponent* WeakpointGlow;
    UParticleSystemComponent* SmokeParticles;
    UParticleSystemComponent* SmokeParticlesNS;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator MainBodyRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* DestroyedMesh;
    USoundCue* ExplosionSound;
    UFXSystemAsset* ExplosionEffect;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ATowerEventModule* PreviousModule;
    ATowerEventModule* NextModule;
    UStaticMesh* ArmorMesh;
    int32 ArmorPieces;
    float ArmorLifetime;
    float ArmorPopForce;
    float ArmorShedDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> ArmorMeshes;
    ATowerEventModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttack();
    UFUNCTION(BlueprintCallable)
    void HideArmorPlates();
    void DestroyArmor();
    // Fix for true pure virtual functions not being implemented
};
