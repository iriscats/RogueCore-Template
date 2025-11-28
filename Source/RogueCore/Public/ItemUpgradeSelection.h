#pragma once
#include "CoreMinimal.h"

#include "ItemUpgradeSelection.generated.h"

USTRUCT(BlueprintType)
struct FItemUpgradeSelection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid WeaponID;
    
    TArray<FGuid> EquippedUpgrades;
    TArray<FGuid> PermanentUpgrades;
    FGuid EquippedOverclock;
    TArray<FGuid> EquippedSkins;
    bool OverclockingUnlocked;
 
    FGuid EquippedSkinColor;
    FGuid EquippedSkinMesh;
    ROGUECORE_API FItemUpgradeSelection();
};
