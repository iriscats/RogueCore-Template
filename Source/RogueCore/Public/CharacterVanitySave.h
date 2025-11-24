#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterVanityLoadout.h"
#include "EVanitySlot.h"
#include "CharacterVanitySave.generated.h"

class UVanityItem;
USTRUCT(BlueprintType)
struct FCharacterVanitySave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterVanityLoadout> Loadouts;

    FCharacterVanityLoadout RandomVanityLoadout;
    TArray<FGuid> UnLockedVanityItemIDs;
    TArray<UVanityItem*> UnLockedVanityItems;
    TMap<EVanitySlot, FGuid> NewVanityItems;

    ROGUECORE_API FCharacterVanitySave();
private:
};
