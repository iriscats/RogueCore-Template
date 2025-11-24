#pragma once
#include "CoreMinimal.h"
#include "EItemPreviewStatus.h"
#include "EUpgradeCalucationType.h"
#include "UpgradeValues.generated.h"

USTRUCT(BlueprintType)
struct FUpgradeValues {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float BaseValue;
    
    float UpgradedValue;
    float UpgradedPercentageValue;
    float OldUpgradedValue;
    float OldUpgradedPercentageValue;
    float CurrentValue;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUpgradeCalucationType CalculationType;
    EItemPreviewStatus PreviewStatus;
    ROGUECORE_API FUpgradeValues();
};
