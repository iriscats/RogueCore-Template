#pragma once
#include "CoreMinimal.h"
#include "TXEnemyPool.generated.h"

USTRUCT(BlueprintType)
struct FTXEnemyPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXEnemyPool();
};
