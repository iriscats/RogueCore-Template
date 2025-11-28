#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RewardTreeLockWidget.generated.h"

class UObject;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API URewardTreeLockWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredForUnlock;
    
    URewardTreeLockWidget();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool IsLocked(UObject* WorldContextObject) const;
    int32 GetNumberOfNodesBought(UObject* WorldContextObject) const;
};
