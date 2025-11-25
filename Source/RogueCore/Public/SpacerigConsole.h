#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpacerigConsole.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API ASpacerigConsole : public AActor {
    GENERATED_BODY()
public:
    ASpacerigConsole(const FObjectInitializer& ObjectInitializer);
};
