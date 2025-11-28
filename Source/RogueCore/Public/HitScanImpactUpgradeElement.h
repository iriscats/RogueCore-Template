#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "HitScanImpactUpgradeElement.generated.h"

class UFXSystemAsset;
class USoundCue;
UCLASS(Blueprintable, EditInlineNew)
class UHitScanImpactUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFXSystemAsset> ImpactParticle;
    
    TSoftObjectPtr<USoundCue> ImpactSound;
    UHitScanImpactUpgradeElement();
};
