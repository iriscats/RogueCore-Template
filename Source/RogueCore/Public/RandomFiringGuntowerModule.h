#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HostileGuntowerModule.h"
#include "RandomFiringGuntowerModule.generated.h"

class UAudioComponent;
class UDamageComponent;
class UFXSystemAsset;
class UNiagaraComponent;
class UParticleSystemComponent;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class ARandomFiringGuntowerModule : public AHostileGuntowerModule {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LaserFrontTop;
    
    UStaticMeshComponent* LaserFrontBottom;
    UStaticMeshComponent* LaserBackTop;
    UStaticMeshComponent* LaserBackBottom;
    UParticleSystemComponent* FrontTopLaserMuzzle;
    UParticleSystemComponent* FrontBottomLaserMuzzle;
    UParticleSystemComponent* BackTopLaserMuzzle;
    UParticleSystemComponent* BackBottomLaserMuzzle;
    UNiagaraComponent* FrontTopLaserMuzzleNS;
    UNiagaraComponent* FrontBottomLaserMuzzleNS;
    UNiagaraComponent* BackTopLaserMuzzleNS;
    UNiagaraComponent* BackBottomLaserMuzzleNS;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FRotator OtherCurrentRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* LaserImpact;
    UAudioComponent* LaserSound;
    UDamageComponent* Damage;
    float BoneSpaceTurretMaxYaw;
    float BoneSpaceTurretMaxPitch;
    float TimeBetweenAttacks;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeUntilNextAttack;
    float ModuleRotationSpeed;
    float TurretAimSpeed;
    float LaserLeghtRatio;
    float TimeBetweenHits;
    float ChanceToInvert;
    float PlatformDissolveRadius;
    float PlatformDissolveSqueeze;
    bool IsAttacking;
    ARandomFiringGuntowerModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
