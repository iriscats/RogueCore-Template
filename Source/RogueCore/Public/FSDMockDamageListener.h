#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageListener.h"
#include "FSDMockDamageListener.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFSDMockDamageListener : public UActorComponent, public IDamageListener {
    GENERATED_BODY()
public:
    UFSDMockDamageListener(const FObjectInitializer& ObjectInitializer);
    // Fix for true pure virtual functions not being implemented
};
