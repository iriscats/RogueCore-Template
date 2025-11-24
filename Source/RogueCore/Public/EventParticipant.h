#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EventParticipant.generated.h"

class AGameEvent;
UINTERFACE(Blueprintable)
class ROGUECORE_API UEventParticipant : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IEventParticipant : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool SetupEvent(AGameEvent* GameEvent);
    
    void OnEventTriggered();
    void OnEventProgress(float Progress);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEventOpened();
    void OnEventFinished(bool eventSuccess);
    bool AdvanceOneObjective();
    bool AddEventProgress(float Progress);
};
