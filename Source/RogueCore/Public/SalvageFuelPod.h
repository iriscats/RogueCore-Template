#pragma once
#include "CoreMinimal.h"
#include "RessuplyPod.h"
#include "SalvageFuelPod.generated.h"

UCLASS(Blueprintable, NoExport)
class ASalvageFuelPod : public ARessuplyPod {
    GENERATED_BODY()
public:
    ASalvageFuelPod(const FObjectInitializer& ObjectInitializer);
};
