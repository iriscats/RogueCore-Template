#pragma once
#include "CoreMinimal.h"
#include "TXEnemySpawnData.generated.h"

USTRUCT(BlueprintType)
struct FTXEnemySpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnemyName;
    
    FString EnemyType;
    int32 EnemySuccessCount;
    ROGUECORE_API FTXEnemySpawnData();
};
