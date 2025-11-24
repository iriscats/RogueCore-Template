#pragma once
#include "CoreMinimal.h"
#include "HoldButton.generated.h"

USTRUCT(BlueprintType)
struct FHoldButton {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText HoldingText;
    
    float HoldStartTime;
    float HoldDuration;
    ROGUECORE_API FHoldButton();
};
