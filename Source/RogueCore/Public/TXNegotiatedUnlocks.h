#pragma once
#include "CoreMinimal.h"
#include "TXUnlockUpgrade.h"
#include "TXNegotiatedUnlocks.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiatedUnlocks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString Rarity;
    FString Type;
    int32 max_ammo;
    int32 current_ammo;
    TArray<FTXUnlockUpgrade> upgrades;
    ROGUECORE_API FTXNegotiatedUnlocks();
};
