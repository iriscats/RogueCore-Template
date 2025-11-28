#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedItem.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "ThrowableItem.generated.h"

class AActor;
class AItem;
class AThrowableActor;
class UAnimMontage;
class UItemUpgrade;
UCLASS(Blueprintable)
class AThrowableItem : public AAnimatedItem, public IUpgradable {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AThrowableActor> ThrowableClass;
    
    UAnimMontage* FPThrowMontage;
    UAnimMontage* TPThrowMontage;
    float ThrowVelocity;
    float InheritOwnerVelocityScale;
    float ThrowAngle;
    float CooldownAfterThrow;
    bool CanThrowBeforeEquipAnimFinish;
    float CooldownAfterEquip;
    float ThrowDelay;
    FVector ThrowOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float CooldownLeft;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> upgrades;
    TSubclassOf<AItem> LoadoutItem;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AThrowableActor>> ThrownActors;
    AThrowableItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool StartThrow();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Simulate_Throw(TSubclassOf<AThrowableActor> ActorClass);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Throw(TSubclassOf<AThrowableActor> ActorClass, const FVector& Location);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemThrown(AThrowableActor* thrownActor);
    void ReceiveItemSpawned(AThrowableActor* thrownActor);
    void OnThrownActorDestroyed(AActor* Actor);
    // Fix for true pure virtual functions not being implemented
};
