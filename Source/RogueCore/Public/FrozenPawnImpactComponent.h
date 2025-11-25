#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"

#include "DelegateDelegate.h"
#include "FrozenPawnImpactComponent.generated.h"

class AActor;
class UFXSystemAsset;
class UPhysicalMaterial;
class UPhysicsAsset;
class UPrimitiveComponent;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFrozenPawnImpactComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnStartFallingEvent;
    
    FDelegate OnFreezeImpactEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* FrozenMaterial;
    UPhysicsAsset* FrozenAsset;
    USoundCue* FrozenDeathSound;
    UFXSystemAsset* FrozenDeathParticles;
    UFrozenPawnImpactComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerFrozenRagdoll();
    void OnFrozen(bool frozen);
    void OnFreezeImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
