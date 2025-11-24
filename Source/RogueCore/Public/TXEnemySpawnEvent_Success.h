#pragma once
#include "CoreMinimal.h"
#include "TXEnemySpawnEvent_Success.generated.h"

USTRUCT(BlueprintType)
struct FTXEnemySpawnEvent_Success {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString enemy_type;
    
    int32 enemy_count;
    ROGUECORE_API FTXEnemySpawnEvent_Success();
};
