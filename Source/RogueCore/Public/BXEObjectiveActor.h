#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BXEObjectiveActor.generated.h"

class UBXEBlueprintControlledObjective;
UINTERFACE(Blueprintable)
class ROGUECORE_API UBXEObjectiveActor : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IBXEObjectiveActor : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SpawnedFromObjective(UBXEBlueprintControlledObjective* InObjective);
};
    
