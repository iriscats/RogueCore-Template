#pragma once
#include "CoreMinimal.h"
#include "AggregatorVisibilityChangedDelegateDelegate.h"
#include "ItemAggregator.h"
#include "UsableAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUsableAggregator : public UItemAggregator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAggregatorVisibilityChangedDelegate OnVisibilityChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UsingText;
    UUsableAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    float GetProgress();
};
