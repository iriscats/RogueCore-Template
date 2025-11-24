#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "RunState.h"
#include "RunStatistics.h"
#include "BXEGameStateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXEGameStateComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewDeficultyDelegate, int32, DifficultyIndex);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnEndLevelFadeOutFinished;
protected:
    FNewDeficultyDelegate OnNewDifficulty;
    FDelegate OnNewDifficultySoonWarning;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_RunState, meta=(AllowPrivateAccess=true))
    FRunState RunState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_RunStatistics, meta=(AllowPrivateAccess=true))
    FRunStatistics RunStatistics;
    UBXEGameStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void SignalNewDifficultyStartingSoon() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void SignalNewDifficulty(int32 DifficultyIndex) const;
    UFUNCTION(BlueprintCallable)
    void OnRep_RunStatistics();
    UFUNCTION()
    void OnRep_RunState();
    void OnFadeOutCompleted();
    void FadeOutAllPlayersInSloMotion();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_FadeOutLocalPlayer();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_FadeInLocalPlayer();
};
