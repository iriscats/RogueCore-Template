#pragma once
#include "CoreMinimal.h"
#include "RoomFeature.h"
#include "RandomSelector.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URandomSelector : public URoomFeature {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 min;
    
    int32 max;
    URandomSelector();
};
