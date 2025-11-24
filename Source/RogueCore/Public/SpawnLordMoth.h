#pragma once
#include "CoreMinimal.h"
#include "CoreSpawnEnemyBase.h"
#include "SpawnLordMoth.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ASpawnLordMoth : public ACoreSpawnEnemyBase {
    GENERATED_BODY()
public:
    ASpawnLordMoth(const FObjectInitializer& ObjectInitializer);
};
