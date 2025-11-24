#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ClaimableRewardEntry.h"
#include "ClaimableRewardEntryWidget.generated.h"

class UClaimableRewardEntryWidget;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UClaimableRewardEntryWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWidgetDelegate, UClaimableRewardEntryWidget*, EntryWidget);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetDelegate OnRewardClaimed;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClaimableRewardEntry Data;
    FText ButtonText;
    UClaimableRewardEntryWidget();
    UFUNCTION(BlueprintCallable)
    void SignalRewardClaimed();
    void SetData(FClaimableRewardEntry InData);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveMoveIn(float InStartDelay);
    void ReceiveDataChanged();
    void MoveIn(float InStartDelay);
};
