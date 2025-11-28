#pragma once
#include "CoreMinimal.h"

#include "Styling/SlateTypes.h"
#include "Blueprint/UserWidget.h"
#include "EFSDInputSource.h"
#include "InputDisplay.h"
#include "RichTextInputWidget.generated.h"

class URichTextBlock;
class UTextBlock;
UCLASS(Abstract, Blueprintable, EditInlineNew, HideDropdown)
class URichTextInputWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputName;
    
    TMap<FName, FString> MetaData;
    FText Content;
    FTextBlockStyle TextStyle;
    EFSDInputSource InputSource;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URichTextBlock* RichTextBlock;
    URichTextInputWidget();
    UFUNCTION(BlueprintCallable)
    void ScaleTextBlockToHeight(UTextBlock* InTextBlock, float LineHeight);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveInputUnknown();
    void ReceiveInputDetails(const FInputDisplay& InDisplay);
    void OnInputSourceChanged(EFSDInputSource InSource);
    void OnCustomKeyBindsChanged();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D MeasureTextSize(const FText& Text, float Scale) const;
    float GetLineHeight() const;
    void ApplyTextStyle(UTextBlock* InTextBlock, const FTextBlockStyle& InTextStyle);
};
