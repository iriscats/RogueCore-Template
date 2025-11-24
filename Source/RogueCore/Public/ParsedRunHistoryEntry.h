#pragma once
#include "CoreMinimal.h"
#include "ParsedRunHistoryCharacterData.h"
#include "SharedRunData.h"
#include "ParsedRunHistoryEntry.generated.h"

class URunTemplate;
USTRUCT(BlueprintType)
struct ROGUECORE_API FParsedRunHistoryEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URunTemplate* TargetTemplate;
    
    FSharedRunData SharedInfo;
    TArray<FParsedRunHistoryCharacterData> Characters;
    FParsedRunHistoryEntry();
};
