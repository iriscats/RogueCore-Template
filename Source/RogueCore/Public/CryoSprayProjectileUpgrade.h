#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "CryoSprayProjectileUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
class AProjectile;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UCryoSprayProjectileUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFireCost;
    
    float BaseArch;
    TSubclassOf<AProjectile> ProjectileClass;
    UCryoSprayProjectileUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, TSubclassOf<AProjectile> NewProjectileClass);
};
