#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActiveCampaignItem.h"
#include "WeeklyCampaignItem.h"
#include "CampaignSave.generated.h"

USTRUCT(BlueprintType)
struct FCampaignSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveCampaignItem ActiveCampaign;

    TArray<FGuid> CompletedCampaigns;
    int32 ActiveCampaignWeek;
    ROGUECORE_API FCampaignSave();
 
    FWeeklyCampaignItem WeeklySave;
    FWeeklyCampaignItem MaxtrixCoreHuntSave;
    FWeeklyCampaignItem SeededRandomSave;
};
