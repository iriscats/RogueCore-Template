#pragma once
#include "CoreMinimal.h"
#include "VoteOptionAction.h"
#include "WarningVoteOptionAction.generated.h"

class URiskVector;
UCLASS(Blueprintable, EditInlineNew)
class UWarningVoteOptionAction : public UVoteOptionAction {
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URiskVector* RiskVector;
    
    UWarningVoteOptionAction();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URiskVector* GetRiskVector() const;
};
