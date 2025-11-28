#pragma once
#include "CoreMinimal.h"
#include "ECoilgunUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "CoilgunUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UCoilgunUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECoilgunUpgrades upgradeType;
    
    UCoilgunUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, ECoilgunUpgrades NewUpgradeType);
};
