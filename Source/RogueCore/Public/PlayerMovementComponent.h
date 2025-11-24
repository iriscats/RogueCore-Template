#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"

class AActor;
class APlayerCharacter;
class UCharacterStateComponent;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerMovementComponent : public UCharacterMovementComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))

    TWeakObjectPtr<UCharacterStateComponent> CurrentPhysUpdateState;

    UPlayerMovementComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void RemoveGravityModifier(AActor* SourceActor);



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJumpOffDelegate);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DebugFastMove;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SlidingOnIceSound;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnJumpOffDelegate OnJumpOff;
protected:
    float LedgeClimbZVelocity;
    float MovementPenalty;
    APlayerCharacter* Character;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCharacterStateComponent> CurrentPhysUpdateState;
    UPlayerMovementComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveGravityModifier(AActor* SourceActor);
    void AddGravityModifier(AActor* SourceActor, float Effect);
};
