#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemAquisitionBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UItemAquisitionBase : public UDataAsset {
    GENERATED_BODY()
public:
    UItemAquisitionBase();
};
