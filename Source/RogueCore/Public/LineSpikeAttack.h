#pragma once
#include "CoreMinimal.h"
#include "SpecialAttackComponent.h"
#include "Templates/SubclassOf.h"
#include "LineSpikeAttack.generated.h"

class AActor;
class ULineSpikeTaskBase;
class UMaterialInstance;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULineSpikeAttack : public USpecialAttackComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TentacleMaterial;
    
    UMaterialInstance* ActiveMaterial;
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UNiagaraComponent>> ActiveParticles;
    UNiagaraSystem* TentacleImpactParticles;
    UNiagaraSystem* StartWaveParticles;
    USoundCue* TentacleImpactSound;
    USoundCue* TentacleExitSound;
    USoundCue* StartWaveSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* Tentacles;
    TArray<ULineSpikeTaskBase*> Sequence;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Children;
    int32 SequenceLoops;
    TSubclassOf<AActor> SpikeClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TentaclesBurried, meta=(AllowPrivateAccess=true))
    bool TentaclesBurried;
    float MaxStepUpheight;
    float firstSpikeDelay;
    float MaxDistanceToGround;
    float DistanceBetweenSpikes;
    float TimeBetweenSpikes;
    float TentacleStretchPower;
    float TentacleSearchDistance;
    float TentacleInGroundOffset;
    int32 MinSpikeCount;
    int32 MaxFails;
    ULineSpikeAttack(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_TentaclesBurried();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayEffects();
};
