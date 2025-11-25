#pragma once
#include "CoreMinimal.h"
#include "EDetPackUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "DetPackUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UDetPackUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDetPackUpgrades upgradeType;
    
    UDetPackUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, EDetPackUpgrades NewUpgradeType);
};
