#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrierProjectile.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ABarrierProjectile : public AActor {
    GENERATED_BODY()
public:
    ABarrierProjectile(const FObjectInitializer& ObjectInitializer);
};
