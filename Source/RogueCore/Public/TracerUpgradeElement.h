#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "TracerUpgradeElement.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, EditInlineNew)
class UTracerUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFXSystemAsset> Tracer;
    
    UTracerUpgradeElement();
};
