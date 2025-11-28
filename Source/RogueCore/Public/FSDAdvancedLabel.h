#pragma once
#include "CoreMinimal.h"

#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "Blueprint/UserWidget.h"
#include "ActionIconMapping.h"
#include "EFSDInputSource.h"
#include "FSDAdvancedLabel.generated.h"

class UHorizontalBox;
class UImage;
class UTextBlock;
class UTexture2D;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFSDAdvancedLabel : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText FormattedText;
    
    FText ControllerOverrideText;
    bool UpperCase;
    EFSDInputSource PreviewAs;
    UFSDAdvancedLabel();
    UFUNCTION(BlueprintCallable)
    void SetText(FText NewText, FText OverrideControllerText);
    void SetAlwaysShowAs(EFSDInputSource InPreferredSource);
    void Refresh();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReset();
    void OnNewLine(int32 Index);
    void OnLanguageChanged(const FString& NewCulture);
    void OnInputSourceChanged(EFSDInputSource Source);
    void OnAddString(const FString& Value);
    void OnAddKeyName(const FString& Name);
    void OnAddIcon(const FString& Name, const FActionIconMapping& Icon);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetText();
    bool GetIsDesignTime() const;
    EFSDInputSource GetCurrentInputSource() const;
    UTextBlock* CreateTextBlock(const FString& Text, FSlateFontInfo InFontInfo, FLinearColor Color);
    UImage* CreateImageSized(UTexture2D* Texture, int32 Width, int32 Height);
    UImage* CreateImage(UTexture2D* Texture, bool MatchSize);
    UHorizontalBox* CreateHorizontalBox();
};
