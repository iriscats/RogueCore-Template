#pragma once
#include "CoreMinimal.h"
#include "EnemySpawnItem.generated.h"

class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FEnemySpawnItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* Enemy;
    
    int32 count;
    float VeteranComposition;
    ROGUECORE_API FEnemySpawnItem();
};
