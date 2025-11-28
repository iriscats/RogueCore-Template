#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RewardWidget.generated.h"

class UReward;
UCLASS(Blueprintable, EditInlineNew)
class URewardWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReward* Reward;
    
    URewardWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayReceiveAnim();
};
