#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RewardClaimedDelegate.h"
#include "SeasonLevel.h"
#include "SeasonLevelWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USeasonLevelWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRewardClaimed OnRewardClaimed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    int32 SeasonLevel;
    bool IsNormalClaimed;
    bool IsSpecialClaimed;
    bool IsUnlocked;
    bool IsLastInRow;
    FSeasonLevel LevelInfo;
    USeasonLevelWidget();
    UFUNCTION(BlueprintCallable)
    bool TryClaimReward(bool isNormalReward);
    void SetData(int32 inLevel, bool inLastInRow);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RefreshState();
    void OnDataSet();
};
