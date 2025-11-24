#pragma once
#include "CoreMinimal.h"
#include "DelegateDelegate.h"
#include "WindowWidget.h"
#include "WorkbenchWindowWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWorkbenchWindowWidget : public UWindowWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnUpgradeSelected;
    
    UWorkbenchWindowWidget();
};
