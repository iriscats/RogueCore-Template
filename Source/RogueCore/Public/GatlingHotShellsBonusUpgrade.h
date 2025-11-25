#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "GatlingHotShellsBonusUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class UDamageClass;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UGatlingHotShellsBonusUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageClass;
    
    float ConversionPercentage;
    bool DamageIsAdded;
    float TemperatureRequired;
    UGatlingHotShellsBonusUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, UDamageClass* NewDamageClass);
};
