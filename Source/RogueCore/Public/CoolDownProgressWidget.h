#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CoolDownProgressStyle.h"
#include "CoolDownProgressWidget.generated.h"

class UObject;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCoolDownProgressWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCoolDownProgressStyle Style;
    
    TWeakObjectPtr<UObject> CoolDownObject;
    bool bIsFinished;
    UCoolDownProgressWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateProgress(float Progress);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUpdateProgress(float InProgress);
    void ReceiveInitWidget();
    void Init(UObject* InCoolDownObject, const FCoolDownProgressStyle& InStyle);
};
