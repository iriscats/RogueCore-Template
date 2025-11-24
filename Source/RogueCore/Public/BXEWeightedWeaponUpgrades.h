#pragma once
#include "CoreMinimal.h"
#include "BXEWeightedWeaponUpgrades.generated.h"

class UItemUpgrade;
USTRUCT(BlueprintType)
struct FBXEWeightedWeaponUpgrades {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UItemUpgrade> upgrade;

    float Weight;
    ROGUECORE_API FBXEWeightedWeaponUpgrades();

    bool operator==(const FBXEWeightedWeaponUpgrades& Other) const
    {
        return upgrade == Other.upgrade && Weight == Other.Weight;
    }
};

FORCEINLINE uint32 GetTypeHash(const FBXEWeightedWeaponUpgrades& Upgrades)
{
    uint32 Hash = 0;
    Hash = HashCombine(Hash, GetTypeHash(Upgrades.upgrade));
    Hash = HashCombine(Hash, GetTypeHash(Upgrades.Weight));
    return Hash;
}
