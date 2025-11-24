#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AccessLibrary.generated.h"

class AActor;
class UAccessCondition;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API UAccessLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAccessLibrary();
    UFUNCTION(BlueprintCallable)
    static void RemoveTemporaryAccessConditionToActor(AActor* Actor, UAccessCondition* Condition);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void RemovePermanentAccessConditionFromLocalPlayer(UObject* WorldContext, UAccessCondition* Condition);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DoesActorHaveAccessCondition(const AActor* Actor, const UAccessCondition* Condition);
    static void AddTemporaryAccessConditionToActor(AActor* Actor, UAccessCondition* Condition);
    static void AddPermanentAccessConditionToLocalPlayer(UObject* WorldContext, UAccessCondition* Condition);
};
