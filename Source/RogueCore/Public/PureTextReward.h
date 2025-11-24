#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "PureTextReward.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPureTextReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPureTextReward();
};
