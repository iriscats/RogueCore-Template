#pragma once
#include "CoreMinimal.h"
#include "EnemyMinersManualStats.generated.h"

USTRUCT(BlueprintType)
struct FEnemyMinersManualStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Health;
    
    int32 Damage;
    int32 Speed;
    ROGUECORE_API FEnemyMinersManualStats();
};
