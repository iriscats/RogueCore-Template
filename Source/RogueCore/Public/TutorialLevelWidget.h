#pragma once
#include "CoreMinimal.h"
#include "FSDUserWidget.h"
#include "Templates/SubclassOf.h"
#include "TutorialLevelWidget.generated.h"

class UTutorialContentWidget;
UCLASS(Blueprintable, EditInlineNew)
class UTutorialLevelWidget : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBetweenTutorials;
    
    UTutorialLevelWidget();
    UFUNCTION(BlueprintCallable)
    void ShowTutorialWidget(TSubclassOf<UTutorialContentWidget> TutorialWidget, bool ignoreQueue);
    void RemoveTutorialWidget(UTutorialContentWidget* TutorialWidget);
    void RemoveAllTutorials();
    void OnTutorialFinished(UTutorialContentWidget* TutorialWidget);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNewActiveTutorial(UTutorialContentWidget* Widget);
};
