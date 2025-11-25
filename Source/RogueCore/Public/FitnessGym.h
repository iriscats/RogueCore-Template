#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnNewGoalDelegateDelegate.h"
#include "OnRepCompletedDelegateDelegate.h"
#include "OnRepNewHighscoreDelegateDelegate.h"
#include "OnSetCompletedDelegateDelegate.h"
#include "FitnessGym.generated.h"

class ABaseFitnessActivity;
class AGymDisplay;
class AOmegaBartender;
class APlayerCharacter;
class UTexture2D;
UCLASS(Blueprintable, NoExport)
class AFitnessGym : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRepCompletedDelegate OnRepCompleted;

    FOnSetCompletedDelegate OnSetCompleted;
    FOnRepNewHighscoreDelegate OnNewHighscore;
    FOnNewGoalDelegate OnNewGoal;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ABaseFitnessActivity*> activities;
    TArray<AGymDisplay*> GymMonitors;
    AOmegaBartender* Bartender;
    int32 GymCreditPerSet;
    TArray<APlayerCharacter*> ActivePlayers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RepPerSet, meta=(AllowPrivateAccess=true))
    int32 RepPerSet;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 RepsRemaining;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SetsRemainingChanged, meta=(AllowPrivateAccess=true))
    int32 SetsRemaining;
 
    AFitnessGym(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopCharacterFromHoveringActivities(APlayerCharacter* Character);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetNewDisplayNumbers();
    void SetMonitors(TArray<AGymDisplay*> monitors);
    void SetBartender(AOmegaBartender* aBartender);
    void SetActivities(TArray<ABaseFitnessActivity*> NewActivities);
    UFUNCTION()
    void OnRep_SetsRemainingChanged(int32 Old);
    UFUNCTION()
    void OnRep_RepPerSet();
    void NewGoal(const int32 SetGoal, const int32 RepsPerSet);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSetsRemaining() const;
    int32 GetRepsRemaining() const;
    int32 GetRepPerSet() const;
    TArray<AGymDisplay*> GetGymMonitors();
    void GetAcitivityIcons(TArray<UTexture2D*>& outTextures, TArray<int32>& outIDs) const;
    int32 GetAcitivityAmount() const;
    bool CanPlayerStartActivity(APlayerCharacter* Player);
    void AllowCharacterToHoverActivities(APlayerCharacter* Character);
};
