#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "StatusAddedComponent.generated.h"

class AActor;
class UStatusEffect;
UINTERFACE(Blueprintable)
class ROGUECORE_API UStatusAddedComponent : public UInterface {
    GENERATED_BODY()
};
class ROGUECORE_API IStatusAddedComponent : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitializeEffect(UStatusEffect* Effect, AActor* EffectOwner);
};

