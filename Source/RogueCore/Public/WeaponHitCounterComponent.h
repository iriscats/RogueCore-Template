#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponHitCounterComponent.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPrimitiveComponent;
class UWeaponHitCountEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponHitCounterComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    bool RequiresWeakpointHit;

    UWeaponHitCounterComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Reliable, Server)

    void Server_OnReloading();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponHitCountEffect* HitEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequiresWeakpointHit;
    UWeaponHitCounterComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_OnReloading();
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    void OnStoppedUsing();
    void OnReloading();
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowDamageEffects(const TArray<TWeakObjectPtr<AActor>>& Targets);
};
