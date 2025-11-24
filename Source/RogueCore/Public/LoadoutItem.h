#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "LoadoutItem.generated.h"

class AItem;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API ULoadoutItem : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ILoadoutItem : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual TSubclassOf<AItem> GetLoadoutItemClass() const PURE_VIRTUAL(GetLoadoutItemClass, return NULL;);
};
    
