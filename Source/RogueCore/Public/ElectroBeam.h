#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Engine/NetSerialization.h"
#include "DelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "ElectroBeam.generated.h"

class UAudioComponent;
class UCapsuleComponent;
class UHealthComponentBase;
class UNiagaraComponent;
class USceneComponent;
class UStatusEffect;
UCLASS(Abstract, Blueprintable)
class AElectroBeam : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* collider;

    USceneComponent* SceneRoot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ParentPlants;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SourceLocation, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize SourceLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TargetLocation, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize TargetLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* DelaySource;
    USceneComponent* DelayTarget;
    UNiagaraComponent* BeamEffectNS;
    UAudioComponent* ZappSound;
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToApply;
    float MaxLitTime;
    float MinLitTime;
    float MaxUnlitTime;
    float MinUnlitTime;
    bool ShouldFlicker;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnLitChanged;

    bool IgnorePlayerOverlap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsLit, meta=(AllowPrivateAccess=true))
    bool IsLit;
    AElectroBeam(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTarget(USceneComponent* TargetPoint);
    void SetSource(USceneComponent* SourcePoint);
    void SetParents(AActor* firstParent, AActor* secondParent);
    void SetIsLit(bool NewLit);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_TargetActorSet_Server(AActor* NewTarget);
    void Receive_SourceActorSet_Server(AActor* NewSource);
    void RecalculateBeam();
    UFUNCTION()
    void OnRep_TargetLocation();
    UFUNCTION()
    void OnRep_SourceLocation();
    UFUNCTION()
    void OnRep_IsLit();
    void OnParentDeath(UHealthComponentBase* HealthComponent);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsLit() const;
    UCapsuleComponent* GetCollider();
    UAudioComponent* GetAudio();
    void DelayedSetTarget(USceneComponent* TargetPoint);
    void DelayedSetSource(USceneComponent* SourcePoint);
    void DeactivateCollisionAndEffect();
};
