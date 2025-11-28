#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "FearAoEBonusUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UFearAoEBonusUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FearFactor;
    
    float Range;
    UFearAoEBonusUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player);
};
