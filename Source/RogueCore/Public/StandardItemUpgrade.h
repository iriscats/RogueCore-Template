#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "StandardItemUpgrade.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UStandardItemUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float amount;
    
    bool IsPercentage;
    bool AlwaysRoundValueUp;
    UStandardItemUpgrade();
};
