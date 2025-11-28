#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "ThrowableActor.generated.h"

class APlayerCharacter;
class UProjectileMovementComponent;
class USoundCue;
UCLASS(Blueprintable)
class AThrowableActor : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ImpactGroundSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent* Movement;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsMoving, meta=(AllowPrivateAccess=true))
    bool IsMoving;
    bool IgnoreFellOutOfWorld;
    bool IgnoreOwnersCollision;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastImpactTime;
    AThrowableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveIgnoreCharacter(APlayerCharacter* Character);
    void ReceiveHitObject();
    UFUNCTION(BlueprintCallable)
    void OnRep_IsMoving();
    void OnActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
