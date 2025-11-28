#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UnlockReward.h"
#include "PermanentItemUpgradeReward.generated.h"

class AActor;
class UItemUpgrade;
UCLASS(Blueprintable, EditInlineNew)
class UPermanentItemUpgradeReward : public UUnlockReward {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Item;
    
    UItemUpgrade* upgrade;
    UPermanentItemUpgradeReward();
};
