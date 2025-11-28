#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "MilestoneTier.h"
#include "OnMilestoneClaimedDelegate.h"
#include "OnMilestoneReachedDelegate.h"
#include "MilestoneAsset.generated.h"

class UMilestoneAsset;
class UMissionStat;
class UObject;
class UPlayerCharacterID;
class UTexture2D;
UCLASS(Blueprintable)
class UMilestoneAsset : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnMilestoneClaimed OnMilestoneClaimed;
    
    FOnMilestoneReached OnMilestoneReached;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    TSoftObjectPtr<UTexture2D> LargeImage;
    FText FormattedTitle;
    int32 FormattedValueOffset;
    bool CountValueAsTotal;
    UMissionStat* TrackingStat;
    UPlayerCharacterID* TrackingCharacterID;
    TArray<FMilestoneTier> Tiers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastTierReached;
    bool bPendingMilestoneReached;
    UMilestoneAsset();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UMilestoneAsset*> SortMilestonesByProgress(UObject* WorldContext, UPARAM(Ref) TArray<UMilestoneAsset*>& Milestones);
    void OnMissionStatChanged(UObject* WorldContext, UMissionStat* Stat, float Value, float change);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsCompleted(UObject* WorldContext) const;
    bool IsClaimable(UObject* WorldContext);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTitleForTier(int32 Tier) const;
    FText GetTitle(const UObject* WorldContext) const;
    int32 GetNextPerkPointsReward(UObject* WorldContext) const;
    void GetCurrentProgress(const UObject* WorldContext, int32& Tier, float& Progress, float& CurrentCount, float& TargetCount) const;
    int32 GetClaimedTier(const UObject* WorldContext) const;
    bool GetClaimedProgress(UObject* WorldContext, int32& Tier, float& Progress, float& CurrentCount, float& TargetCount);
    UTexture2D* GetCategoryIcon() const;
    UFUNCTION(BlueprintCallable)
    void ClearPendingMilestoneReached();
    int32 ClaimNextTier(UObject* WorldContext);
};
