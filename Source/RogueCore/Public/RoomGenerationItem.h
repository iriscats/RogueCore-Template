#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "RoomGenerationItem.generated.h"

UCLASS(Blueprintable, NoExport)
class ARoomGenerationItem : public AGenerationItem {
    GENERATED_BODY()
public:
    ARoomGenerationItem(const FObjectInitializer& ObjectInitializer);
};
