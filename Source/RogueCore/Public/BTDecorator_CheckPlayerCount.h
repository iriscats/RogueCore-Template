#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CheckPlayerCount.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CheckPlayerCount : public UBTDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerCount;
    
    bool AllowLessThanCount;
    UBTDecorator_CheckPlayerCount();
};
