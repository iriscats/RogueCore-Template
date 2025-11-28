#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "EGymAnimationState.h"
#include "OnCanStrikeDelegateDelegate.h"
#include "OnForceSetRepsDelegateDelegate.h"
#include "OnIFrameDelegateDelegate.h"
#include "OnLivesChangedDelegateDelegate.h"
#include "OnNewPBDelegateDelegate.h"
#include "OnRepTimerChangedDelegateDelegate.h"
#include "OnStrikeDelegateDelegate.h"
#include "ThresholdChangedDelegateDelegate.h"
#include "ValueChangedDelegateDelegate.h"
#include "FitnessGymStateComponent.generated.h"

class ABaseFitnessActivity;
class APlayerCharacter;
class UAnimSequence;
class UGymMinigameBaseWidget;
class UInputComponent;
class UTexture2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UFitnessGymStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLivesChangedDelegate OnLivesChanged;
    
    FOnStrikeDelegate OnStrike;
    FOnIFrameDelegate OnIFrame;
    FOnNewPBDelegate OnNewPB;
    FOnForceSetRepsDelegate OnForceSetReps;
    FOnCanStrikeDelegate OnCanStrikeChanged;
    FValueChangedDelegate OnValueChanged;
    FOnRepTimerChangedDelegate OnRepTimerChanged;
    FThresholdChangedDelegate OnThresholdChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* FitnessInputComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_GymActivity, meta=(AllowPrivateAccess=true))
    ABaseFitnessActivity* GymActivity;
    TArray<UGymMinigameBaseWidget*> MiniGameWidgets;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2D* CurrentExerciseIcon;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AnimState, meta=(AllowPrivateAccess=true))
    EGymAnimationState CurrentAnimState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_StressLevel, meta=(AllowPrivateAccess=true))
    float StressLevel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RepsPerSet, meta=(AllowPrivateAccess=true))
    int32 RepsPerSet;
    UFitnessGymStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Client, Reliable)
    virtual void TamperWithEquipment();
    UFUNCTION(BlueprintCallable)
    void StartActivity_Implementation(ABaseFitnessActivity* Activity);
    virtual void SetIFrame(const bool On);
    void SetHitSize(float Size);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetGymIcon(UTexture2D* Icon);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    virtual void SetComplete();
    UFUNCTION(Server, Reliable)
    virtual void VisiblityChanged(bool visible);
    UFUNCTION(Server, Reliable)
    virtual void SetCharacterStartPosition();
    UFUNCTION(Server, Reliable)
    virtual void SendStressLevels(float Stress);
    UFUNCTION(Server, Reliable)
    virtual void ForceEndActivity();
    UFUNCTION(Server, Reliable)
    virtual void EndActivity();
    UFUNCTION(Server, Reliable)
    virtual void ChangeAnimState(EGymAnimationState NewState);
    UFUNCTION(Reliable, Server)
    virtual void SendScore(int32 score);
    UFUNCTION(Reliable, Server)
    virtual void SendPersonalBest(int32 score);
    UFUNCTION(Client, Reliable)
    virtual void RepComplete();
    UFUNCTION()
    void OnRep_StressLevel();
    UFUNCTION()
    void OnRep_RepsPerSet();
    UFUNCTION()
    void OnRep_GymActivity();
    UFUNCTION()
    void OnRep_AnimState(EGymAnimationState oldState);
    void OnNewGoalRecieved(int32 Sets, int32 RepsPerSets);
    void IncreaseSpeedWithInterval();
    void IncreaseSpeed(float amount);
    void IncreaseDifficultyWithInterval();
    void IncreaseDifficulty(int32 amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRepsLeft_Implementation() const;
    int32 GetPersonalBest();
    UAnimSequence* GetAnimSequence(EGymAnimationState State);
    void ForceEndActivity(APlayerCharacter* Player);
    void AnimNotifyCheck(FName NotifyName);
    void AddMiniGameHUD(int32 Index, UGymMinigameBaseWidget* HUD);
};
