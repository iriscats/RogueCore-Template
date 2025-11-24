#pragma once
#include "CoreMinimal.h"
#include "FSDUserWidget.h"
#include "TutorialWidget.generated.h"

class UTexture2D;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UTutorialWidget : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    float RemainingVisibleTime;

    

    UTutorialWidget();

    UFUNCTION(BlueprintCallable)

    void Show(const FText& Text, const FText& Title, const FText& TaskText, UTexture2D* Image, float Duration);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RemainingVisibleTime;
    
    UTutorialWidget();
    UFUNCTION(BlueprintCallable)
    void Show(const FText& Text, const FText& Title, const FText& TaskText, UTexture2D* Image, float Duration);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShow(const FText& Text, const FText& Title, const FText& TaskText, UTexture2D* Image);
    void OnHide(bool watched);
    void Hide(bool watched);
    void ChangeHintDuration(float NewDuration);
};
