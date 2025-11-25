#pragma once
#include "CoreMinimal.h"

#include "SpecialDamageAttackComponent.h"
#include "TremorAttackComponent.generated.h"

class AActor;
class UBoxComponent;
class UFXSystemComponent;
class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTremorAttackComponent : public USpecialDamageAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsAttackActive, meta=(AllowPrivateAccess=true))
    bool IsAttackActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBoxComponent* CollisionComponent;
    UFXSystemComponent* ParticlesComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialParticlesDelay;
    float PostParticleDelay;
    float TargetMaxDistanceFromGround;
    float TimeBetweenDamageTicks;
    float LaunchForce;
    float Duration;
    UTremorAttackComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopParticles();
    void StartParticles();
    void OnTargetExitedTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnTargetEnteredTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnRep_IsAttackActive();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInited() const;
    void InitTremorAttack(UBoxComponent* Box, UFXSystemComponent* Particles);
};
