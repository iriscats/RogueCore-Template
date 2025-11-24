#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInfo.h"
#include "DamageListenerData.h"
#include "DamageParams.h"
#include "DamageListener.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UDamageListener : public UInterface {
	GENERATED_BODY()
};

class IDamageListener : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnTrigger(const TArray<FDamageListenerData>& listenerData, const FDamageParams& Params, const FDamageInfo& Damage, int32 eventInfo);
};

