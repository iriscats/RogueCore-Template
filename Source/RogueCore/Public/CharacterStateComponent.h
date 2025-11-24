#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ECharacterState.h"
#include "PlaySoundInterface.h"
#include "CharacterStateComponent.generated.h"

class APlayerCharacter;
class UDialogDataAsset;
class UPlayerMovementComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterStateComponent : public UActorComponent, public IPlaySoundInterface {
    GENERATED_BODY()

public:
    UCharacterStateComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStateTick(float DeltaTime);

    void ReceiveStateExit();

    void ReceiveStateEnter();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;

    bool HasAuthority() const;

    ECharacterState GetStateType() const;

    float GetStateTime() const;

    uint8 GetStateID() const;

    bool GetStateActive() const;

    UPlayerMovementComponent* GetCharacterMovement() const;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 StateId;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;

    UDialogDataAsset* EnterStateShout;

    UDialogDataAsset* ExitStateShout;

    UDialogDataAsset* AttentionShout;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerMovementComponent* PlayerMovement;
};
