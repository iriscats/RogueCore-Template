#pragma once
#include "CoreMinimal.h"

#include "AchievementSaveEntry.generated.h"

USTRUCT(BlueprintType)
struct FAchievementSaveEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid AchievementSaveID;
    
    float HighestSavedProgress;
    float currentProgress;
    ROGUECORE_API FAchievementSaveEntry();
};
