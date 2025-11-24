#pragma once
#include "CoreMinimal.h"
#include "VanityMasterySettings.generated.h"

USTRUCT(BlueprintType)
struct FVanityMasterySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalMasteryLevels;
    
    int32 XP_RequiredPerLevel;
    int32 XP_ForCreditSpent;
    int32 XP_ForMineralSpent;
    int32 FashionitesLevelUpReward;
    ROGUECORE_API FVanityMasterySettings();
};
