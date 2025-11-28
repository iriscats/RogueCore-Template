#pragma once
#include "CoreMinimal.h"
#include "EBeltDrivenWeaponUpgrade.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "BeltDrivenWeaponUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UBeltDrivenWeaponUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeltDrivenWeaponUpgrade upgradeType;
    
    UBeltDrivenWeaponUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EBeltDrivenWeaponUpgrade NewUpgradeType);
};
