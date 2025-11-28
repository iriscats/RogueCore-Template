#pragma once
#include "CoreMinimal.h"

#include "UObject/Interface.h"
#include "EMinersManualSection.h"
#include "EMinersManualSinglePage.h"
#include "MinersManualHandler.generated.h"

UINTERFACE(Blueprintable)
class ROGUECORE_API UMinersManualHandler : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IMinersManualHandler : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OpenMinersManualPage(EMinersManualSinglePage page);
    
    void OpenMinersManualFromID(EMinersManualSection Section, const FGuid& ID);
};
