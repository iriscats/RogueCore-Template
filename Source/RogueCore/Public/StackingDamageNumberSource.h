#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EUpdateDamageNumberColor.h"
#include "StackingDamageNumberSource.generated.h"

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UStackingDamageNumberSource : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IStackingDamageNumberSource : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual float GetStackingTimeLimit() const PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    
    virtual int32 GetMaxCombinationsPerentry() const PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    virtual EUpdateDamageNumberColor GetColorBehaviour() const PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
