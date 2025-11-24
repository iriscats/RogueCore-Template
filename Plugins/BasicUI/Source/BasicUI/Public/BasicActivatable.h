#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BasicActivatable.generated.h"

UINTERFACE(Blueprintable)
class UBasicActivatable : public UInterface {
    GENERATED_BODY()
};

class IBasicActivatable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivated();
    
};

