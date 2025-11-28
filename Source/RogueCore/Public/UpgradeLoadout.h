#pragma once
#include "CoreMinimal.h"

#include "ItemUpgradeSelection.h"
#include "UpgradeLoadout.generated.h"

USTRUCT(BlueprintType)
struct FUpgradeLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FItemUpgradeSelection> Loadout;

    ROGUECORE_API FUpgradeLoadout();
 
};
