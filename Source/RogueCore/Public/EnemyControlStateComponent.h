#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterStateComponent.h"
#include "ControlEnemyState.h"
#include "EEnemyControlState.h"
#include "EnemyControlStateComponent.generated.h"

class UAIPlayerControlComponent;
class UAnimMontage;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEnemyControlStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseThirdPersonCam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_StateData, meta=(AllowPrivateAccess=true))
    FControlEnemyState StateData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ControlState, meta=(AllowPrivateAccess=true))
    EEnemyControlState ControlState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FQuat AngularVelocity;
    FQuat ControlRotation;
    UEnemyControlStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerExit();
    UFUNCTION(BlueprintCallable)
    void OnRep_StateData(const FControlEnemyState& oldState);
    UFUNCTION()
    void OnRep_ControlState(EEnemyControlState oldState);
    void OnEnemyCrashMontageEnded(UAnimMontage* Montage, bool interrupted);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnControllingEnemyAttached();
    void OnControllingEnemy(bool IsControlling);
    void JumpPressed();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAIPlayerControlComponent* GetAiPlayerControlComponent();
};
