#pragma once
#include "CoreMinimal.h"
#include "RetirementCostItem.h"
#include "Templates/SubclassOf.h"
#include "GDCharacterRetirement.generated.h"

class UCampaign;
class UPlayerCharacterID;
USTRUCT(BlueprintType)
struct FGDCharacterRetirement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, TSubclassOf<UCampaign>> Campaigns;
    
    TMap<UPlayerCharacterID*, FRetirementCostItem> RetirementCost;
    TArray<float> CreditsCostMultipliers;
    TArray<float> ResourceCostMultipliers;
    ROGUECORE_API FGDCharacterRetirement();
};
