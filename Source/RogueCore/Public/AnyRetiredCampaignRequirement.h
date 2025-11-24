#pragma once
#include "CoreMinimal.h"
#include "CampaignRequirement.h"
#include "AnyRetiredCampaignRequirement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UAnyRetiredCampaignRequirement : public UCampaignRequirement {
    GENERATED_BODY()
public:
    UAnyRetiredCampaignRequirement();
};
