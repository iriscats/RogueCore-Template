#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ClaimableRewardEntry.h"
#include "PendingRewards.h"
#include "PendingRewardsStats.h"
#include "RewardsSubSystem.generated.h"

class AFSDPlayerController;
class UObject;
UCLASS(Blueprintable)
class URewardsSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPendingRewards PendingMissionRewards;
    
    TArray<FClaimableRewardEntry> PendingPromotionRewards;
    URewardsSubSystem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldPendingRewardsBeShown() const;
    bool ShouldPendingRewardsBeGiven() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool Receive_GetPendingRewards(UObject* WorldContext, FPendingRewardsStats& OutStats, FPendingRewards& OutRewards) const;
    bool HasPendingRewards() const;
    bool GetPendingRewards(FPendingRewardsStats& OutStats, FPendingRewards& OutRewards) const;
    UFUNCTION(BlueprintCallable)
    void ClearPendingRewards();
    void ApplyPendingRewards(AFSDPlayerController* Controller);
};
