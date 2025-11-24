#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SavedBoosterDecks.generated.h"

USTRUCT(BlueprintType)
struct FSavedBoosterDecks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> DeckIDs;

    ROGUECORE_API FSavedBoosterDecks();
protected:
};
