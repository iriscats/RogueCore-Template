#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "EffectTriggeredDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "StatusEffectTriggerComponent.generated.h"

class AActor;
class UPrimitiveComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStatusEffectTriggerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEffectTriggeredDelegate OnEffectTriggered;
    
    FEffectTriggeredDelegate OnActorEnterLeave;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffects;
    TArray<TSubclassOf<UStatusEffect>> LeaveTriggerEffects;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* collider;
    bool RemoveStatusEffectOnEndOverlap;
    UStatusEffectTriggerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetCollider(UPrimitiveComponent* Primitive);
    void OnOverlapEnd(AActor* MyActor, AActor* OtherActor);
    void OnOverlapBegin(AActor* MyActor, AActor* OtherActor);
    void OnComponentOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnComponentOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void AddActorToIgnoreList(AActor* Actor);
};
