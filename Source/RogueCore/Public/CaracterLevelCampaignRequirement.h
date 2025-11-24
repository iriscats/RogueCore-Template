#pragma once
#include "CoreMinimal.h"
#include "CampaignRequirement.h"
#include "CaracterLevelCampaignRequirement.generated.h"

class UPlayerCharacterID;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UCaracterLevelCampaignRequirement : public UCampaignRequirement {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* characterID;

    int32 LevelRequirement;

public:
    UCaracterLevelCampaignRequirement();
};
