#pragma once
#include "CoreMinimal.h"
#include "FuelLineSegment.h"
#include "TetherFuelLineSegment.generated.h"

UCLASS(Blueprintable, NoExport)
class ATetherFuelLineSegment : public AFuelLineSegment {
    GENERATED_BODY()
public:
    ATetherFuelLineSegment(const FObjectInitializer& ObjectInitializer);
};
