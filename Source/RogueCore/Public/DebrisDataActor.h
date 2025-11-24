#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebrisDataActor.generated.h"

UCLASS(Abstract, Blueprintable, NoExport)
class ADebrisDataActor : public AActor {
    GENERATED_BODY()
public:
    ADebrisDataActor(const FObjectInitializer& ObjectInitializer);
};
