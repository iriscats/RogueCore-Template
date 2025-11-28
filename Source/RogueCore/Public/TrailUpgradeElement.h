#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "TrailUpgradeElement.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, EditInlineNew)
class UTrailUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFXSystemAsset> Trail;
    
    UTrailUpgradeElement();
};
