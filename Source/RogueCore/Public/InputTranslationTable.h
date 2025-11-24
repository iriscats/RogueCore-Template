#pragma once
#include "CoreMinimal.h"
#include "InputTranslation.h"
#include "InputTranslationTable.generated.h"

USTRUCT(BlueprintType)
struct FInputTranslationTable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FInputTranslation> Entries;

    ROGUECORE_API FInputTranslationTable();

};
