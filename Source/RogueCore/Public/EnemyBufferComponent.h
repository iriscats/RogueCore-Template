#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "BoolDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "EnemyBufferComponent.generated.h"

class AFSDPawn;
class UFXSystemAsset;
class UFXSystemComponent;
class UHealthComponentBase;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyBufferComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    TArray<UFXSystemComponent*> ParticleInstances;

    UEnemyBufferComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    FName BufferParticleSocket;
    UFXSystemAsset* Particles;
    float ParticleTangentSize;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnBuffingChangedEvent;
    float BuffRadius;
    int32 MaxBuffedTargets;
    FGameplayTagQuery BuffQuery;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<AFSDPawn*> BuffTargets;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFXSystemComponent*> ParticleInstances;
    UEnemyBufferComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetBuffingEnabled(bool Enabled);
    void OnPawnDied(UHealthComponentBase* Health);
    void OnOwnerDied(UHealthComponentBase* Health);
};
