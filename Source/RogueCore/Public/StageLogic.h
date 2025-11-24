#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StageLogic.generated.h"

UCLASS(Blueprintable)
class UStageLogic : public UObject {
    GENERATED_BODY()
public:
    UStageLogic();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartLogic();
    
};
