#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CampaignNotification.generated.h"

class UCampaign;
class UCampaignMission;
UCLASS(Blueprintable)
class UCampaignNotification : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCampaign* Campaign;
    
    UCampaignMission* Mission;
    int32 Progress;
    bool bIsCampaignCompleted;
    UCampaignNotification();
};
