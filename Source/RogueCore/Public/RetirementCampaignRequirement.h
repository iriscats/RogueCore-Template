#pragma once
#include "CoreMinimal.h"
#include "CampaignRequirement.h"
#include "RetirementCampaignRequirement.generated.h"

class UPlayerCharacterID;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API URetirementCampaignRequirement : public UCampaignRequirement {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* characterID;
    
    int32 LevelRequirement;
    URetirementCampaignRequirement();
};
