#pragma once
#include "CoreMinimal.h"
#include "EnemyGroupDescriptor.h"
#include "AmberEventEnemyPool.generated.h"

UCLASS(Blueprintable)
class UAmberEventEnemyPool : public UEnemyGroupDescriptor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTimeBetweenSpawn;
    
    float MinTimeBetweenSpawn;
    int32 MaxEnemyCap;
    int32 AmbersNeededdToComplete;
    int32 AmbersNeededOnePlayer;
    UAmberEventEnemyPool();
};
