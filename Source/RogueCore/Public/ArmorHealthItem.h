#pragma once
#include "CoreMinimal.h"
#include "ArmorHealthSubItem.h"
#include "ArmorHealthItem.generated.h"

USTRUCT(BlueprintType)
struct FArmorHealthItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaterialIndex;
    
    bool HealthIsBreakPercentage;
    bool OverrideAffectedByAmorBreak;
    bool NewAffectedByArmorBreak;
    bool OverrideArmorDamageEnabled;
    TArray<FArmorHealthSubItem> ArmorBones;
    ROGUECORE_API FArmorHealthItem();
};
