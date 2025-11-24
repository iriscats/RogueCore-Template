#pragma once
#include "CoreMinimal.h"
#include "FSDTaskInfo.h"
#include "FSDThreadGroup.h"
#include "FSDTerrainGenerationStats.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FFSDTerrainGenerationStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentAsyncTaskDescription;
    
    FString PLSPass;
    int32 NumRunningTasks;
    TArray<FFSDThreadGroup> ThreadGroups;
    TArray<FFSDTaskInfo> RunningTasks;
    TArray<FFSDTaskInfo> FinishedTasks;
    FFSDTerrainGenerationStats();
};
