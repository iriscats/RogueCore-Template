#pragma once
#include "CoreMinimal.h"
#include "ItemAquisitionBase.h"
#include "UnlockedAquisition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UUnlockedAquisition : public UItemAquisitionBase {
    GENERATED_BODY()
public:
    UUnlockedAquisition();
};
