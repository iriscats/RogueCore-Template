#pragma once
#include "CoreMinimal.h"

#include "CampaignRequirement.h"
#include "WeeklyTimerCampaignRequirement.generated.h"

class AFSDPlayerController;
class UCampaign;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UWeeklyTimerCampaignRequirement : public UCampaignRequirement {
    GENERATED_BODY()
public:
    UWeeklyTimerCampaignRequirement();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetWeeklyTimeLeft(AFSDPlayerController* Player) const;
    
    FTimespan GetTimeUntillNewCampaign(AFSDPlayerController* Player) const;
    bool GetHasCompleted(UCampaign* Campaign, AFSDPlayerController* Player) const;
};
