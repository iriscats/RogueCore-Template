#pragma once
#include "CoreMinimal.h"
#include "TXEnemySpawnEvent_Failures.h"
#include "TXEnemySpawnEvent_Success.h"
#include "TXEnemySpawnEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXEnemySpawnEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXEnemySpawnEvent_Success> success;
    
    TArray<FTXEnemySpawnEvent_Failures> failures;
    ROGUECORE_API FTXEnemySpawnEvent();
};
