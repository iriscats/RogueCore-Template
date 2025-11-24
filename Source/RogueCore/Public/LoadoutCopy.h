#pragma once
#include "CoreMinimal.h"
#include "CharacterPerksSave.h"
#include "CharacterVanityLoadout.h"
#include "ItemLoadout.h"
#include "UpgradeLoadout.h"
#include "LoadoutCopy.generated.h"

USTRUCT(BlueprintType)
struct FLoadoutCopy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemLoadout ItemLoadout;
    
    FUpgradeLoadout UpgradeLoadout;
    FCharacterPerksSave PerkLoadout;
    FCharacterVanityLoadout VanityLoadout;
    ROGUECORE_API FLoadoutCopy();
};
