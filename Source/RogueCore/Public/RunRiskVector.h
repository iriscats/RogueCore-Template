#pragma once
#include "CoreMinimal.h"
#include "RunRiskVector.generated.h"

class URiskVector;
USTRUCT(BlueprintType)
struct FRunRiskVector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URiskVector* RiskVector;
    
    int32 StageIndexWhenAdded;
    bool IsRunPersistent;
    ROGUECORE_API FRunRiskVector();
};
