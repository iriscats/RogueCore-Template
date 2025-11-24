#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SaveGameSnapShot.generated.h"

class APlayerCharacter;
class UFSDSaveGame;
class UResourceData;
USTRUCT(BlueprintType)
struct FSaveGameSnapShot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UFSDSaveGame> SaveGame;
    
    FString Filename;
    bool IsObsolete;
    int32 VersionNumber;
    int32 Credits;
    TMap<TSubclassOf<APlayerCharacter>, int32> CharacterLevels;
    TMap<TSubclassOf<UResourceData>, int32> Resources;
    ROGUECORE_API FSaveGameSnapShot();
};
