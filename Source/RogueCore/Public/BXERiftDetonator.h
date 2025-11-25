#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BXERiftDetonator.generated.h"

UCLASS(Blueprintable)
class ABXERiftDetonator : public AActor {
    GENERATED_BODY()
public:
    ABXERiftDetonator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWiresMerged();
    
};
