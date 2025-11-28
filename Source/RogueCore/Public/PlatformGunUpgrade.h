#pragma once
#include "CoreMinimal.h"
#include "EPlatformGunUpgrades.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "PlatformGunUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UPlatformGunUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlatformGunUpgrades myUpgradeType;
    
    UPlatformGunUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(AFSDPlayerState* Player, TSubclassOf<AActor> Item, EPlatformGunUpgrades aUpgradeType);
};
