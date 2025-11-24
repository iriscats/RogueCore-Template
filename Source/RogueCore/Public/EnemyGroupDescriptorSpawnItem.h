#pragma once
#include "CoreMinimal.h"
#include "EnemyGroupDescriptorSpawnItem.generated.h"

class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FEnemyGroupDescriptorSpawnItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* Enemy;
    
    int32 count;
    ROGUECORE_API FEnemyGroupDescriptorSpawnItem();
};
