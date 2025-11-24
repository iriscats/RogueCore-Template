#pragma once
#include "CoreMinimal.h"
#include "EZiplineGunUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "ZiplineGunUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class AZipLineProjectile;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UZiplineGunUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZiplineGunUpgrades upgradeType;
    
    TSubclassOf<AZipLineProjectile> ProjectileClass;
    UZiplineGunUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(AFSDPlayerState* Player, TSubclassOf<AActor> Item, EZiplineGunUpgrades NewUpgradeType);
};
