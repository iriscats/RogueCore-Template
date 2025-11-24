#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "WeaponHitCounterUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class UWeaponHitCounterComponent;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UWeaponHitCounterUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWeaponHitCounterComponent> ComponentClass;
    
    UWeaponHitCounterUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(AFSDPlayerState* Player, TSubclassOf<AActor> Item, TSubclassOf<UWeaponHitCounterComponent> NewComponentClass);
};
