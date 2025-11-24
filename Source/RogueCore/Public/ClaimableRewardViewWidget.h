#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ClaimableRewardView.h"
#include "ClaimableRewardViewWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UClaimableRewardViewWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UClaimableRewardViewWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveEndFlow();

    void ReceiveDataChanged();

    void ReceiveBeginFlow();

    void EndRewardFlow();

    void BeginRewardFlow(FClaimableRewardView InViewData);

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClaimableRewardView Data;
};
