#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TriggerAI.generated.h"

UINTERFACE(Blueprintable)
class ROGUECORE_API UTriggerAI : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ITriggerAI : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnTriggerAI(FName TriggerName);
    
    void OnMessageAI(FName TriggerName);
};
