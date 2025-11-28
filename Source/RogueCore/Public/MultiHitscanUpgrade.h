#pragma once
#include "CoreMinimal.h"
#include "EMultiHitscanUpgradeType.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "MultiHitscanUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UMultiHitscanUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiHitscanUpgradeType upgradeType;
    
    UMultiHitscanUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EMultiHitscanUpgradeType NewUpgradeType);
};
