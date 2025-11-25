#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "TaggedActor.h"
#include "Targetable.h"
#include "Templates/SubclassOf.h"
#include "WormSpawnDelegateDelegate.h"
#include "WormPod.generated.h"

class AActor;
class UAnimMontage;
class UEnemyDescriptor;
class UFXSystemAsset;
class UHealthComponentBase;
class USceneComponent;
class USimpleHealthComponent;
class USkeletalMeshComponent;
class USoundCue;
UCLASS(Blueprintable, NoExport)
class AWormPod : public ATaggedActor, public ITargetable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USceneComponent* ScalePoint;
    USkeletalMeshComponent* PodMesh;
    USimpleHealthComponent* Health;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWormSpawnDelegate OnWormSpawned;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Grown, meta=(AllowPrivateAccess=true))
    bool Grown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* GrowthAnimation;
    UAnimMontage* PopAnimation;
    TSubclassOf<AActor> CarcasActor;
    FRuntimeFloatCurve GrowthCurve;
    UEnemyDescriptor* WormDescriptor;
    UFXSystemAsset* PopParticles;
    UFXSystemAsset* deathParticles;
    USoundCue* PopSound;
    USoundCue* deathSound;
    float ParentDeathDelay;
    float DeathDelayVariance;
    int32 WormCount;
    AWormPod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SpawnWorms();
    UFUNCTION()
    void OnRep_Grown();
    void OnParentDeath(UHealthComponentBase* ParentHealth);
    void OnDeath(UHealthComponentBase* aHealth);
    void OnAnimEnded(UAnimMontage* Montage, bool bInterrupted);
    void Kill();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowDeath(bool success);
    // Fix for true pure virtual functions not being implemented
};
