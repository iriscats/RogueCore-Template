#pragma once
#include "CoreMinimal.h"
#include "EnemySpawnedDelegateDelegate.h"
#include "ManagedEncounterItem.h"
#include "PrePlacedEncounterItem.h"
#include "EncounterManagerItem.generated.h"

USTRUCT(BlueprintType)
struct FEncounterManagerItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FManagedEncounterItem> ManagedEcnounterItems;
    
    TArray<FPrePlacedEncounterItem> PrePlacedEncounterItems;
    int32 ID;
    bool IsRoom;
    FEnemySpawnedDelegate Callback;
    ROGUECORE_API FEncounterManagerItem();
};
