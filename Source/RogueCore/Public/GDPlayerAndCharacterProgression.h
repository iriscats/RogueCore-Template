#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "GDPlayerAndCharacterProgression.generated.h"

class APlayerCharacter;
class UPlayerCharacterID;
USTRUCT(BlueprintType)
struct FGDPlayerAndCharacterProgression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<APlayerCharacter>> RankedHeroClasses;
    
    TArray<TSoftClassPtr<APlayerCharacter>> TestHeroClasses;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APlayerCharacter>> LoadedClasses;
    TArray<FText> PlayerRankNames;
    TArray<int32> CharacterXPLevels;
    TMap<FGuid, UPlayerCharacterID*> PlayerCharacterIDs;
    ROGUECORE_API FGDPlayerAndCharacterProgression();
};
