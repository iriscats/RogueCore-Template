#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockInstance.h"
#include "Templates/SubclassOf.h"
#include "UnlockableItemData.h"
#include "ParsedCharacterBuildData.generated.h"

class APlayerCharacter;
class UPerkAsset;
USTRUCT(BlueprintType)
struct ROGUECORE_API FParsedCharacterBuildData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerName;
    
    int32 PlayerIndex;
    TSubclassOf<APlayerCharacter> PlayerCharacterClass;
    TArray<FBXEUnlockInstance> UnlockRecords;
    TArray<FUnlockableItemData> Items;
    TArray<UPerkAsset*> Enhancements;
    FParsedCharacterBuildData();
};
