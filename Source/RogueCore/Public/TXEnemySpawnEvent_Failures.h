#pragma once
#include "CoreMinimal.h"
#include "TXEnemySpawnEvent_Failures.generated.h"

USTRUCT(BlueprintType)
struct FTXEnemySpawnEvent_Failures {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString enemy_type;
    
    FString enemy_transform;
    ROGUECORE_API FTXEnemySpawnEvent_Failures();
};
