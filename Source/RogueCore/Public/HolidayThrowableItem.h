#pragma once
#include "CoreMinimal.h"
#include "ThrowableItem.h"
#include "HolidayThrowableItem.generated.h"

UCLASS(Blueprintable, NoExport)
class AHolidayThrowableItem : public AThrowableItem {
    GENERATED_BODY()
public:
    AHolidayThrowableItem(const FObjectInitializer& ObjectInitializer);
};
