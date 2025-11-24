#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerReviveLibrary.generated.h"

class AActor;
UCLASS(Blueprintable)
class ROGUECORE_API UPlayerReviveLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPlayerReviveLibrary();
    UFUNCTION(BlueprintCallable)
    static bool MoveActorToDeadPlayerFallbackPosition(AActor* ActorToMove);
    
};
