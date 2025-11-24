#pragma once
#include "CoreMinimal.h"
#include "TickableActionBase.h"
#include "MiniTimerAction.generated.h"

class UMiniTimerAction;
class UObject;
UCLASS(Blueprintable)
class UMiniTimerAction : public UTickableActionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FTickDelegate Completed;

    FTickDelegate OnTick;

    UMiniTimerAction();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))

    static UMiniTimerAction* MiniTimer(UObject* WorldContext, float InDuration);



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTickDelegate, float, DeltaTime, float, NormalizedTime);
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTickDelegate Completed;
    FTickDelegate OnTick;
    UMiniTimerAction();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UMiniTimerAction* MiniTimer(UObject* WorldContext, float InDuration);
};
