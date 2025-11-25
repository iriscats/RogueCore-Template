#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/TimerHandle.h"
#include "Widgets/Layout/Anchors.h"
#include "UObject/UnrealType.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "Blueprint/UserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "SizeBoxSettings.h"
#include "Templates/SubclassOf.h"
#include "WidgetAnimationSettings.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Notifications/SProgressBar.h"
#include "FSDWidgetBlueprintLibrary.generated.h"

class AFSDPlayerState;
class APlayerController;
class UCanvasPanel;
class UCanvasPanelSlot;
class UFSDCheatManager;
class UHorizontalBox;
class UHorizontalBoxSlot;
class UImage;
class UObject;
class UOverlay;
class UOverlaySlot;
class UPanelWidget;
class UProgressBar;
class UScaleBox;
class USizeBox;
class USpacer;
class UTextBlock;
class UTexture2D;
class UUniformGridPanel;
class UUniformGridSlot;
class UUserWidget;
class UVerticalBox;
class UVerticalBoxSlot;
class UWidget;
class UWidgetAnimation;
class UWindowWidget;
UCLASS(Blueprintable)
class UFSDWidgetBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FWidgetDelegate, UUserWidget*, Widget);
    DECLARE_DYNAMIC_DELEGATE_ThreeParams(FWidgetCreatedOrReusedDelegate, bool, WasCreated, UUserWidget*, Widget, int32, ActiveIndex);
    DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FCompareWidgetsDelegate, const UWidget*, InFirstWidget, const UWidget*, InSecondWidget);
    
    UFSDWidgetBlueprintLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ToggleAnimationLooping(UObject* WorldContext, UWidgetAnimation* InAnimation, FWidgetAnimationSettings InSettings, bool InLoop, bool& OutPlayingChanged, bool& OutIsPlaying);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TextSmallerThan(const FText& Text1, const FText& Text2);
    static bool TextGreaterThan(const FText& Text1, const FText& Text2);
    UFUNCTION(BlueprintCallable)
    static TArray<UWidget*> SortWidgetArray(const TArray<UWidget*>& InWidgets, const UFSDWidgetBlueprintLibrary::FCompareWidgetsDelegate& InCompareFunction);
    static void SimpleBox(UPARAM(Ref) FPaintContext& Context, FVector2D position, FVector2D Size, FLinearColor Tint);
    static FTimerHandle SetTimerForNextTick(UObject* WorldContext, const FTimerDynamicDelegate& TimerDelegate);
    static void SetSizeBoxSettings(USizeBox* InSizeBox, const FSizeBoxSettings& InSettings);
    static void SetProgressBarType(UProgressBar* InProgressBar, TEnumAsByte<EProgressBarFillType::Type> InType);
    static void SetOverlaySlot(UWidget* InWidget, TEnumAsByte<EHorizontalAlignment> InHorizontal, TEnumAsByte<EVerticalAlignment> InVertical, FMargin InPadding);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetMousePosition(UObject* WorldContextObject, int32 X, int32 Y);
    static bool SetHorizontalSlot(UWidget* Widget, FSlateChildSize Size, TEnumAsByte<EHorizontalAlignment> HorizontalAlignment, TEnumAsByte<EVerticalAlignment> VerticalAlignment, FMargin Padding);
    static void SetChildrenVisibility(UPanelWidget* Panel, ESlateVisibility Visibility, int32 StartIndex, TSubclassOf<UUserWidget> OptionalClassFilter);
 
    static void SelectVisibility(UWidget* Widget, ESlateVisibility InFalse, ESlateVisibility InTrue, const bool Value, bool& IsVisible, bool& VisibilityChanged, ESlateVisibility& NewVisibility);
    static void ScrubAnimation(UObject* WorldContext, UWidgetAnimation* InAnimation, float Progress01);
    static void ScaleTextBlockToHeight(UTextBlock* TextBlock, float TargetHeight, bool SetMinimimumWidth);
    static void ScaleImageToHeight(UImage* Image, float TargetHeight);
    static void ResetAnimationToStartTime(UUserWidget* Widget, UWidgetAnimation* Animation);
    static void ResetAnimationToEndTime(UUserWidget* Widget, UWidgetAnimation* Animation);
    static void PrintStrings(UObject* WorldContextObject, const TArray<FString>& InStrings, bool bPrintToScreen, bool bPrintToLog, FLinearColor TextColor, float Duration);
    static FString MidIgnoringWhiteSpace(const FString& Source, int32 Index, int32 count);
    static FVector2D MeasureTextSize(const FText& Text, const FSlateFontInfo& Font);
    static FVector2D MeasureTextBlockSize(const UTextBlock* TextBlock);
    static void Line(FPaintContext& Context, FVector2D Pos1, FVector2D Pos2, FLinearColor Tint);
    static FLinearColor LerpColors(const TArray<FLinearColor>& Colors, bool Interpolate, float Progress01);
    static int32 LengthIgnoringWhitespace(const FString& Source);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsWindowsPlatform(UObject* WorldContextObject);
    static bool IsWhiteSpaceAt(const FString& Source, int32 Index);
    static bool IsWhiteSpace(const FString& Source);
    static bool IsHUDVisible(UObject* WorldContextObject);
    static FString IntToRomanNumeral(int32 Value);
    static bool HasAnyVisibleChildren(UPanelWidget* Panel, int32 StartIndex, TSubclassOf<UUserWidget> OptionalClassFilter);
    static FString GetShortTimeString(int32 TotalSeconds, bool BlinkDelimiter);
    static UWindowWidget* GetParentWindowWidget(UUserWidget* InWidget);
    static UUserWidget* GetParentUserWidget(UUserWidget* InWidget);
    static AFSDPlayerState* GetOwningFSDPlayerState(UWidget* Target);
    static FText GetKeyName(const FKey& Key);
    static float GetFontMaxHeight(const FSlateFontInfo& Font);
    static float GetFontBaseline(const FSlateFontInfo& Font);
    static UWidget* GetFocusedWidget(UObject* WorldContextObject, APlayerController* Controller);
    static UUserWidget* GetFocusableParentUserWidget(UUserWidget* InWidget);
    static FVector2D GetDrawSize(UPARAM(Ref) FPaintContext& InContext);
    static UFSDCheatManager* GetCheatManager(UObject* WorldContextObject);
    static TArray<UWidget*> GetAllChildrenOfClass(UPanelWidget* Panel, TSubclassOf<UWidget> WidgetClass);
    static UWidget* FindChildWidget(UPARAM(Ref) UPanelWidget*& ParentWidget, TSubclassOf<UUserWidget> WidgetClass, bool SearchChildren);
    static UVerticalBox* CreateVerticalBox(UObject* WorldContext);
    static UTextBlock* CreateTextBlock(UObject* WorldContext, FText Text, FSlateFontInfo Font, TEnumAsByte<ETextJustify::Type> Justification, FLinearColor Color, bool WrapText);
    static USpacer* CreateSpacer(UObject* WorldContext, FVector2D Size);
    static UScaleBox* CreateScaleBox(UObject* WorldContext, TEnumAsByte<EStretch::Type> InStretch, TEnumAsByte<EStretchDirection::Type> InStretchDirection);
    static TArray<UUserWidget*> CreateOrReuseChildrenWithCallbackEx(UPanelWidget* Panel, int32 count, TSubclassOf<UUserWidget> WidgetClass, const UFSDWidgetBlueprintLibrary::FWidgetCreatedOrReusedDelegate& OnCreatedOrReused, const UFSDWidgetBlueprintLibrary::FWidgetDelegate& OnCollapsed);
    static TArray<UUserWidget*> CreateOrReuseChildrenWithCallback(UPanelWidget* Panel, int32 count, TSubclassOf<UUserWidget> WidgetClass, const UFSDWidgetBlueprintLibrary::FWidgetCreatedOrReusedDelegate& OnCreatedOrReused);
    static TArray<UUserWidget*> CreateOrReuseChildren(UPanelWidget* Panel, int32 count, TSubclassOf<UUserWidget> WidgetClass);
    static UImage* CreateImageSized(UObject* WorldContext, UTexture2D* Texture, FLinearColor Tint, FVector2D Size);
    static UImage* CreateImageFromBrush(UObject* WorldContext, FSlateBrush InBrush, FLinearColor InColorAndOpacity);
    static UImage* CreateImage(UObject* WorldContext, UTexture2D* Texture, FLinearColor Tint, bool AutoSize);
    static UHorizontalBox* CreateHorizontalBox(UObject* WorldContext);
    static FText ClampTextLength(const FText& Text, int32 MaxLength, const FText& CutOffIndicator);
    static void Box(UPARAM(Ref) FPaintContext& Context, FVector2D position, FVector2D Size, const FSlateBrush& Brush, FLinearColor Tint);
    static bool AreWidgetsIntersecting(const UWidget* InWidget1, const UWidget* InWidget2);
    static UWidget* AddWidgetToRow(UVerticalBox* VerticalBox, UWidget* Widget, int32 MaxWidgetsPerRow, float WidgetSpacing, float RowSpacing, UHorizontalBoxSlot*& OutSlot, UHorizontalBox*& OutRow);
    static UWidget* AddChildToVerticalBoxEx(UVerticalBox* VerticalBox, UWidget* Widget, TEnumAsByte<EHorizontalAlignment> HorizontalAlignment, TEnumAsByte<EVerticalAlignment> VerticalAlignment, float Size, FMargin Padding, UVerticalBoxSlot*& OutSlot, UVerticalBox*& OutVerticalBox);
    static UWidget* AddChildToUniformGridEx(UUniformGridPanel* GridPanel, UWidget* Widget, TEnumAsByte<EHorizontalAlignment> HorizontalAlignment, TEnumAsByte<EVerticalAlignment> VerticalAlignment, int32 Column, int32 Row, UUniformGridSlot*& OutSlot, UUniformGridPanel*& OutGridPanel);
    static UWidget* AddChildToOverlayEx(UOverlay* OverlayPanel, UWidget* Widget, TEnumAsByte<EHorizontalAlignment> HorizontalAlignment, TEnumAsByte<EVerticalAlignment> VerticalAlignment, FMargin Padding, UOverlaySlot*& OutSlot, UOverlay*& OutOverlayPanel);
    static UWidget* AddChildToHorizontalBoxEx(UHorizontalBox* HorizontalBox, UWidget* Widget, TEnumAsByte<EHorizontalAlignment> HorizontalAlignment, TEnumAsByte<EVerticalAlignment> VerticalAlignment, float Size, FMargin Padding, UHorizontalBoxSlot*& OutSlot, UHorizontalBox*& OutHorizontalBox);
    static UWidget* AddChildToCanvasEx(UCanvasPanel* CanvasPanel, UWidget* Widget, FAnchors Anchors, FMargin Offsets, bool AutoSize, int32 Z_Order, UCanvasPanelSlot*& OutSlot, UCanvasPanel*& OutCanvasPanel);
};
