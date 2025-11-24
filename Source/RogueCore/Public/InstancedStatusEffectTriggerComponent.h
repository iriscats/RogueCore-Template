#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "InstancedEffectTriggeredDelegateDelegate.h"
#include "InstancedStatusEffectTriggerComponent.generated.h"

class AActor;
class UPrimitiveComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInstancedStatusEffectTriggerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedEffectTriggeredDelegate OnEffectTriggered;
    
    FInstancedEffectTriggeredDelegate OnActorEnterLeave;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStatusEffect*> StatusEffects;
    TArray<UStatusEffect*> LeaveTriggerEffects;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* collider;
    bool RemoveStatusEffectOnEndOverlap;
    UInstancedStatusEffectTriggerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetCollider(UPrimitiveComponent* Primitive);
    void OnOverlapEnd(AActor* MyActor, AActor* OtherActor);
    void OnOverlapBegin(AActor* MyActor, AActor* OtherActor);
    void OnComponentOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnComponentOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void AddActorToIgnoreList(AActor* Actor);
};
