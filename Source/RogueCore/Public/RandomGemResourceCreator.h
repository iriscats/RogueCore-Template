#pragma once
#include "CoreMinimal.h"
#include "GemResourceCreator.h"
#include "RandomGemResourceCreator.generated.h"

class UCurveFloat;
UCLASS(Blueprintable, EditInlineNew)
class URandomGemResourceCreator : public UGemResourceCreator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PlacementDistanceProbabilityCurve;
    
    URandomGemResourceCreator();
};
