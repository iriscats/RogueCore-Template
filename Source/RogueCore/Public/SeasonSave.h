#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SeasonSaveEntry.h"
#include "SeasonSave.generated.h"

USTRUCT(BlueprintType)
struct FSeasonSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FSeasonSaveEntry> Seasons;
    ROGUECORE_API FSeasonSave();
protected:
};
