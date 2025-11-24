#pragma once
#include "CoreMinimal.h"
#include "IRandRange.h"
#include "JettyBootSetting.generated.h"

USTRUCT(BlueprintType)
struct FJettyBootSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange GateCount;
    
    FIRandRange GateSpacing;
    FIRandRange GateOpeningSize;
    ROGUECORE_API FJettyBootSetting();
};
