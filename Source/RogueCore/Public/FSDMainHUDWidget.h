#pragma once
#include "CoreMinimal.h"
#include "BaseHUDWidget.h"
#include "FSDMainHUDWidget.generated.h"

class URadarPointComponent;
class UWidget;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFSDMainHUDWidget : public UBaseHUDWidget {
    GENERATED_BODY()
public:
    UFSDMainHUDWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PushEvent(UWidget* eventWidget, bool Left);
    
    void PopEvent(UWidget* eventWidget, bool Left);
 
    void OnRadarPointAdded(URadarPointComponent* Point);
    UFUNCTION(BlueprintCallable)
    void AddRadarPoint(URadarPointComponent* Point);
};
