#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LostPack.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ALostPack : public AActor {
    GENERATED_BODY()
public:
    ALostPack(const FObjectInitializer& ObjectInitializer);
};
