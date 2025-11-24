#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectiveActor.generated.h"

class UBXEBlueprintControlledObjective;
UINTERFACE(Blueprintable)
class ROGUECORE_API UObjectiveActor : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IObjectiveActor : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetObjective(UBXEBlueprintControlledObjective* Objective);
    
    void SetExpenitePayout(float playout);
    float GetExpenitePayout();
};
