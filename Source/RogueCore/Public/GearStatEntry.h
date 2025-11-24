#pragma once
#include "CoreMinimal.h"
#include "EItemPreviewStatus.h"
#include "GearStatEntry.generated.h"

USTRUCT(BlueprintType)
struct FGearStatEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText Text;
    
    FText Value;
    FText BaseValue;
    FText UpgradeValue;
    EItemPreviewStatus PreviewStatus;
    ROGUECORE_API FGearStatEntry();
};
