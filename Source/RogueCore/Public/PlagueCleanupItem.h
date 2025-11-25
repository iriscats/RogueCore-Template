#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "AnimatedItem.h"
#include "EInputKeys.h"
#include "Throwable.h"
#include "PlagueCleanupItem.generated.h"

class APlayerCharacter;
class UAnimMontage;
class UAudioComponent;
class UBoxComponent;
class UCrosshairAggregator;
class UInstantUsable;
class UKeepInsideWorld;
class UObjective;
class USoundCue;
class USphereComponent;
UCLASS(Blueprintable)
class ROGUECORE_API APlagueCleanupItem : public AAnimatedItem, public IThrowable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* DroppedCollider;
    
    UInstantUsable* PickupUsable;
    USphereComponent* UseSphere;
    UCrosshairAggregator* CrosshairAggregator;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_FireAnimation;
    UAnimMontage* TP_FireAnimation;
    UAnimMontage* FP_Gunsling;
    UAnimMontage* TP_Gunsling;
    UAnimMontage* Item_Gunsling;
    USoundCue* UsingSound;
    float UsingSoundFadeout;
    USoundCue* UsingSoundTail;
    UKeepInsideWorld* KeepInsideWorld;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* UsingSoundInstance;
    float FireRate;
    APlagueCleanupItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_Gunsling();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_EnablePhysics(const FVector_NetQuantize& Direction);
    UFUNCTION(BlueprintCallable)
    void OnPickupUsed(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnObjectiveChanged(UObjective* Objective);
    void OnInRangeChanged(bool InRange);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Gunsling();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_EnablePhysics(const FVector_NetQuantize& Direction);
    // Fix for true pure virtual functions not being implemented
};
