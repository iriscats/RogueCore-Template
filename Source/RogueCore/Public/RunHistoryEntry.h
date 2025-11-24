#pragma once
#include "CoreMinimal.h"
#include "RunHistoryCharacterData.h"
#include "RunHistoryDamageData.h"
#include "SharedRunData.h"
#include "RunHistoryEntry.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FRunHistoryEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RunIndex;
    
    FSharedRunData SharedInfo;
    FRunHistoryCharacterData Characters;
    FRunHistoryDamageData DamageCollection;
    FRunHistoryEntry();
};
