#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "ProjectileUpgradeElement.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, EditInlineNew)
class UProjectileUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFXSystemAsset> NewTrailParticle;
    
    UProjectileUpgradeElement();
};
