#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "PlagueCleaning.generated.h"

class UInfectionPointCleaningComponent;
UINTERFACE(Blueprintable)
class ROGUECORE_API UPlagueCleaning : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IPlagueCleaning : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UInfectionPointCleaningComponent* GetCleaningPoints(FVector fromLocation);
};
    
