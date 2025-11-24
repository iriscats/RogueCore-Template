#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemUpgradeFilter.generated.h"

UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UItemUpgradeFilter : public UObject {
    GENERATED_BODY()
public:
    UItemUpgradeFilter();
};
