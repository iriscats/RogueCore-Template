#pragma once
#include "CoreMinimal.h"
#include "EGrapplingHookUpgrade.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "GrapplingHookUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UGrapplingHookUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGrapplingHookUpgrade upgradeType;
    
    UGrapplingHookUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(AFSDPlayerState* Player, TSubclassOf<AActor> Item, EGrapplingHookUpgrade NewUpgradeType);
};
