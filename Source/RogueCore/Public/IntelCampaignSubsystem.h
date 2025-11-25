#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EIntelChallengeState.h"
#include "EIntelObjectiveState.h"
#include "IntelProgression.h"
#include "Templates/SubclassOf.h"
#include "IntelCampaignSubsystem.generated.h"

class APlayerCharacter;
class UFSDGameInstance;
class UIntelChallenge;
class UIntelObjective;
UCLASS(Blueprintable)
class UIntelCampaignSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIntelSubsystemObjectiveDelegate, UIntelObjective*, Objective);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIntelSubsystemDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIntelSubsystemChallengeDelegate, TSubclassOf<UIntelChallenge>, Challenge);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntelSubsystemDelegate OnIntelPointsChanged;
    FIntelSubsystemChallengeDelegate OnChallengeClaimed;
    FIntelSubsystemObjectiveDelegate OnObjectiveClaimed;
    FIntelSubsystemChallengeDelegate OnChallengeCompleted;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFSDGameInstance* GameInstance;
    TArray<UIntelObjective*> AllObjectives;
    TArray<UIntelObjective*> ActiveObjectives;
    TArray<UIntelChallenge*> ActiveChallenges;
    FIntelProgression RecentProgression;
    UIntelCampaignSubsystem();
    UFUNCTION(BlueprintCallable)
    void SetIntelPoints(const int32 NewIntelPoints);
    void OnWorldChanged();
    void OnLocalPlayerCharacterInitialized(APlayerCharacter* PlayerCharacter);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntelProgression GetRecentIntelProgression() const;
    TArray<UIntelObjective*> GetObjectivesWithState(const EIntelObjectiveState State) const;
    TArray<UIntelObjective*> GetObjectivesThatCanBeClaimed() const;
    EIntelObjectiveState GetObjectiveState(const UIntelObjective* Objective) const;
    int32 GetIntelPoints() const;
    TArray<TSubclassOf<UIntelChallenge>> GetChallengesThatCanBeClaimed() const;
    EIntelChallengeState GetChallengeState(const TSubclassOf<UIntelChallenge> ChallengeClass) const;
    int32 GetChallengeIntelReward(const TSubclassOf<UIntelChallenge> ChallengeClass) const;
    TArray<UIntelObjective*> GetAllObjectives() const;
    TArray<TSubclassOf<UIntelChallenge>> GetActiveChallenges() const;
    UIntelChallenge* FindActiveChallengeOfClass(const TSubclassOf<UIntelChallenge> ChallengeClass) const;
    FText CreateChallengeDescription(const TSubclassOf<UIntelChallenge> ChallengeClass) const;
    void ClaimObjective(UIntelObjective* Objective);
    void ClaimChallenge(const TSubclassOf<UIntelChallenge> ChallengeClass);
};
