#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EUnlockableState.h"
#include "UnlockableObject.generated.h"

class UObject;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UUnlockableObject : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IUnlockableObject : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    virtual bool Unlock(const UObject* WorldContext) PURE_VIRTUAL(Unlock, return false;);
    
    virtual TEnumAsByte<EUnlockableState> GetUnlockableState(const UObject* WorldContext) const PURE_VIRTUAL(GetUnlockableState, return Unlockable;);
};
