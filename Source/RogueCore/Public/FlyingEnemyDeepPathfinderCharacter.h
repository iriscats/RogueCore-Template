#pragma once
#include "CoreMinimal.h"


#include "EnemyDeepPathfinderCharacter.h"
#include "FlyingEnemyDeepPathfinderCharacter.generated.h"

class AActor;
class UFXSystemAsset;
class UPhysicalMaterial;
class UPhysicsAsset;
class UPrimitiveComponent;
class USoundCue;
UCLASS(Blueprintable)
class AFlyingEnemyDeepPathfinderCharacter : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* FrozenMaterial;
    
    UPhysicsAsset* FrozenAsset;
    USoundCue* FrozenDeathSound;
    UFXSystemAsset* FrozenDeathParticles;
    AFlyingEnemyDeepPathfinderCharacter(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerFrozenRagdoll();
    void OnFreezeImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_FreezeImpact();
};
