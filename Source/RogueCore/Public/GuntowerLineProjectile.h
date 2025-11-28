#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Projectile.h"
#include "GuntowerLineProjectile.generated.h"

class UDamageComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class USceneComponent;
UCLASS(Blueprintable)
class AGuntowerLineProjectile : public AProjectile {
    GENERATED_BODY()
    


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLineDestroy, FHitResult, Result);

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLineDestroy OnLineDestroy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* LeftLinePoint;
    USceneComponent* RightLinePoint;
    UDamageComponent* DamageComponent;
    UParticleSystemComponent* BeamParticles;
    UNiagaraComponent* BeamParticlesNS;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlatformDissolveRadius;
    float PlatformDissolveSqueeze;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* HitParticles;
    UNiagaraComponent* HitParticlesNS;
    float TimeBetweenLineChecks;
    AGuntowerLineProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TurnOffParticles();
    void Fire(const FVector& Origin, const FVector& Direction, float Distance);
};
