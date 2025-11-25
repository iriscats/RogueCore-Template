#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EncounterActor.generated.h"

class APawn;
UCLASS(Blueprintable, NoExport)
class AEncounterActor : public AActor {
    GENERATED_BODY()
public:
    AEncounterActor(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_EncounterHasSpawned(APawn* spawnedPawn);
    
};
