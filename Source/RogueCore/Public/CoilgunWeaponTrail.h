#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Templates/SubclassOf.h"
#include "CoilgunWeaponTrail.generated.h"

class UCapsuleComponent;
class UNiagaraComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class ACoilgunWeaponTrail : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UCapsuleComponent* Collision;
    UNiagaraComponent* Trail;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParticleTrailOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TrailHalfLength, meta=(AllowPrivateAccess=true))
    float TrailHalgLength;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SpawnFireTrail, meta=(AllowPrivateAccess=true))
    bool SpawnFireTrail;
    TSubclassOf<UStatusEffect> FireEffect;
    TSubclassOf<UStatusEffect> ElectricEffect;
    TArray<TSubclassOf<UStatusEffect>> EffectsToApply;
    ACoilgunWeaponTrail(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_TrailHalfLength();
    UFUNCTION()
    void OnRep_SpawnFireTrail();
    void OnInited_Callback();
    void OnActorLeaveTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnActorEnteredTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
