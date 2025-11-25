#pragma once
#include "CoreMinimal.h"
#include "GeneratorLine.h"
#include "FacilityGeneratorLine.generated.h"

class ATetherStation;
UCLASS(Blueprintable)
class AFacilityGeneratorLine : public AGeneratorLine {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATetherStation* Station;

 
    
    AFacilityGeneratorLine(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBeginPathFinding();
};
