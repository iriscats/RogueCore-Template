#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HealthModifier.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UHealthModifier : public UObject {
    GENERATED_BODY()
public:
    UHealthModifier();
};
