#pragma once
#include "CoreMinimal.h"
#include "AchievementSaveEntry.h"
#include "AchievementSave.generated.h"

USTRUCT(BlueprintType)
struct FAchievementSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> OfflineAchievedAchievements;

    TArray<FAchievementSaveEntry> AchievementEntries;
    ROGUECORE_API FAchievementSave();
 
};
