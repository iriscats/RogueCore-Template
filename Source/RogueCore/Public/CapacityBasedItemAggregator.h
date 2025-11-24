#pragma once
#include "CoreMinimal.h"
#include "AmountChangedSignatureDelegate.h"
#include "ItemAggregator.h"
#include "ReloadCompleteSignatureDelegate.h"
#include "ReloadStartedSignatureDelegate.h"
#include "ReloadTimeLeftSignatureDelegate.h"
#include "CapacityBasedItemAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCapacityBasedItemAggregator : public UItemAggregator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmountChangedSignature OnCurrentAmountChanged;
    
    FAmountChangedSignature OnMaxAmountChanged;
    FAmountChangedSignature OnClipAndTotalChanged;
    FReloadTimeLeftSignature OnReloadTimeChanged;
    FReloadCompleteSignature OnReloadComplete;
    FReloadStartedSignature OnReloadStarted;
    FAmountChangedSignature OnMaxAmmoCapacityChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool showClipCount;
    UCapacityBasedItemAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReloadStarted();
    void ReloadComplete();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxAmount() const;
    int32 GetCurrentAmount() const;
};
