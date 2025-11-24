#pragma once
#include "CoreMinimal.h"
#include "ESawedOffShotgunUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "SawedOffShotgunUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class USawedOffShotgunUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESawedOffShotgunUpgrades upgradeType;
    
    USawedOffShotgunUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, ESawedOffShotgunUpgrades NewUpgradeType);
};
