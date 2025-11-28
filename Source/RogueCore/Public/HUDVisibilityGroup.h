#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/UnrealType.h"
#include "EHUDVisibilityGroups.h"
#include "EHUDVisibilityMode.h"
#include "EHUDVisibilityPresets.h"
#include "HUDVisibilityRegisteredWidget.h"
#include "HUDVisibilityGroup.generated.h"

class UHUDVisibilityGroup;
class UWidget;
UCLASS(Blueprintable)
class ROGUECORE_API UHUDVisibilityGroup : public UDataAsset {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVisibilityDelegate, UHUDVisibilityGroup*, Group, bool, IsVisible);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FModeDelegate, UHUDVisibilityGroup*, Group, EHUDVisibilityMode, Mode);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModeDelegate OnModeChanged;
    FVisibilityDelegate OnVisibilityChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDVisibilityGroups GroupID;
    FText Title;
    bool AllowDynamicMode;
    bool AllowHiddenMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDynamicallyVisible;
    TArray<FHUDVisibilityRegisteredWidget> RegisteredWidgets;
    EHUDVisibilityMode RecommendedMode;
    EHUDVisibilityMode MinimalMode;
    UHUDVisibilityGroup();
    UFUNCTION(BlueprintCallable)
    void SetModeFromPreset(EHUDVisibilityPresets Preset);
    void SetMode(EHUDVisibilityMode InMode);
    static void SetHudGroupDynamicallyVisible(UHUDVisibilityGroup* Group, bool IsVisible);
    void SetGroupDynamicallyVisible(bool IsVisible);
    static void RegisterWidgetWithVisibilityGroup(UWidget* Widget, UHUDVisibilityGroup* Group, ESlateVisibility VisibleMode, ESlateVisibility HiddenMode);
    static void RegisterMultipleWidgetsWithVisibilityGroup(TArray<UWidget*> Widgets, UHUDVisibilityGroup* Group, ESlateVisibility VisibleMode, ESlateVisibility HiddenMode);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsModeAllowed(EHUDVisibilityMode InMode) const;
    bool IsInDynamicMode() const;
    static bool IsHudGroupVisible(UHUDVisibilityGroup* Group);
    bool IsGroupVisible() const;
    EHUDVisibilityMode GetMode() const;
    TArray<EHUDVisibilityMode> GetAllowedModes() const;
};
