#pragma once
#include "CoreMinimal.h"
#include "PickaxeMeshPart.h"
#include "PickaxeBladePart.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPickaxeBladePart : public UPickaxeMeshPart {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RestrictedToBackside;
    
    UPickaxeBladePart();
};
