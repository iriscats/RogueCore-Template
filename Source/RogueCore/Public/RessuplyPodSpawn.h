#pragma once
#include "CoreMinimal.h"
#include "RessuplyPod.h"
#include "RessuplyPodSpawn.generated.h"

class AFSDPlayerController;
class APlayerCharacter;
UCLASS(Blueprintable, NoExport)
class ARessuplyPodSpawn : public ARessuplyPod {
    GENERATED_BODY()
public:
    ARessuplyPodSpawn(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetController(AFSDPlayerController* Controller);
    
    void SetCharacter(APlayerCharacter* Character);
};
