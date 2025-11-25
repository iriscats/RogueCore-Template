#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveWidget.generated.h"

class UObjective;
class UObjectiveWidget;
class UTexture2D;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UObjectiveWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectiveWidgetDelegate, UObjectiveWidget*, InObjectiveWidget);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectiveWidgetDelegate OnObjectiveWidgetUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjective* MissionObjective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPrimaryObjective;
    FText ObjectiveText;
    FText ObjectiveCounterText;
    UTexture2D* ObjectiveCounterIcon;
    bool bObjectiveCompleted;
    UObjectiveWidget();
    UFUNCTION(BlueprintCallable)
    void SetText(const FText& InText, const FText& InCounterText, UTexture2D* InCounterIcon, bool InObjectiveCompleted);
    void SetSimpleText(const FText& InText, bool InObjectiveCompleted);
    void SetObjective(UObjective* InObjective, bool InIsPrimaryObjective);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveObjectiveUpdated();
    void ReceiveObjectiveInitialized();
    void OnObjectiveUpdated(UObjective* InObjective);
};
