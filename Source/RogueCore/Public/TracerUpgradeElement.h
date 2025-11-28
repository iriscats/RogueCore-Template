#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "TracerUpgradeElement.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, EditInlineNew)
class UTracerUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFXSystemAsset> Tracer;
    
    UTracerUpgradeElement();
};
