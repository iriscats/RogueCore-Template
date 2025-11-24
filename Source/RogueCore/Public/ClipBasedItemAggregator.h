#pragma once
#include "CoreMinimal.h"
#include "AmountChangedSignatureDelegate.h"
#include "ItemAggregator.h"
#include "ReloadCompleteSignatureDelegate.h"
#include "ReloadStartedSignatureDelegate.h"
#include "ReloadTimeLeftSignatureDelegate.h"
#include "ClipBasedItemAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UClipBasedItemAggregator : public UItemAggregator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmountChangedSignature OnClipCountChanged;
    
    FAmountChangedSignature OnClipCapacityChanged;
    FAmountChangedSignature OnReserveCountChanged;
    FAmountChangedSignature OnReserveCapacityChanged;
    FAmountChangedSignature OnTotalCountChanged;
    FReloadTimeLeftSignature OnReloadTimeChanged;
    FReloadCompleteSignature OnReloadComplete;
    FReloadStartedSignature OnReloadStarted;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowTotalAmount;
    bool ShowClipAndTotalAsOne;
    UClipBasedItemAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReloadStarted();
    void ReloadComplete();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetReserveCount() const;
    int32 GetReserveCapacity() const;
    int32 GetClipCount() const;
    int32 GetClipCapacity() const;
};
