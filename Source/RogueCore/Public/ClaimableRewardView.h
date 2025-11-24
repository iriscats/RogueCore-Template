#pragma once
#include "CoreMinimal.h"
#include "ClaimableRewardEntry.h"
#include "ClaimableRewardView.generated.h"

class UDialogDataAsset;
class USoundCue;
class UUserWidget;
USTRUCT(BlueprintType)
struct FClaimableRewardView {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* MissionControlSpeak;
    
    TSoftClassPtr<UUserWidget> BackgroundWidgetClass;
    TSoftObjectPtr<USoundCue> FanfareAudio;
    float MoveInRewardsDelay;
    TArray<FClaimableRewardEntry> RewardDisplays;
    FText ClaimButtonText;
    ROGUECORE_API FClaimableRewardView();
};
