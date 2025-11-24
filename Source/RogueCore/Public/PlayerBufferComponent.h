#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoolDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "PlayerBufferComponent.generated.h"

class APlayerCharacter;
class UFXSystemAsset;
class UFXSystemComponent;
class UHealthComponentBase;
class UMeshComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerBufferComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    TArray<UFXSystemComponent*> ParticleInstances;

    UPlayerBufferComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* ManualMeshReference;
    FName BufferParticleSocket;
    UFXSystemAsset* Particles;
    float ParticleTangentSize;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnBuffingChangedEvent;
    float BuffRadius;
    int32 MaxBuffedTargets;
    int32 PushAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> BuffTargets;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFXSystemComponent*> ParticleInstances;
    UPlayerBufferComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetBuffingEnabled(bool Enabled);
    void ReducePushAmount();
    void OnPawnDied(UHealthComponentBase* Health);
    void OnOwnerDied(UHealthComponentBase* Health);
};
