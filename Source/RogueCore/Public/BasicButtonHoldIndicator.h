#pragma once
#include "CoreMinimal.h"
#include "BasicUserWidget.h"

#include "ButtonHoldSettings.h"
#include "BasicButtonHoldIndicator.generated.h"

class UBasicButtonHoldIndicator;
class UBasicButtonHoldIndicatorAsset;
class UButton;
class UImage;
class UMaterialInstanceDynamic;
class UOverlay;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UBasicButtonHoldIndicator : public UBasicUserWidget {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoldingDelegate, UBasicButtonHoldIndicator*, HoldIndicator);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoldCompletedDelegate, UBasicButtonHoldIndicator*, HoldIndicator);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoldingDelegate OnHoldProgressChanged;
    FHoldCompletedDelegate OnHoldCompleted;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UButton> Button;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBasicButtonHoldIndicatorAsset* SettingsAsset;
    bool bOverrideBrushSize;
    FVector2D OverrideBrushSize;
    bool bOverrideHoldDuration;
    float OverrideHoldDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FButtonHoldSettings Settings;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UButton> ButtonInstance;
    TWeakObjectPtr<UOverlay> RootOverlay;
    TWeakObjectPtr<UImage> Image;
    TWeakObjectPtr<UMaterialInstanceDynamic> DynamicMaterial;
    float HoldProgress;
    bool bHolding;
    UBasicButtonHoldIndicator();
    UFUNCTION(BlueprintCallable)
    void SetButton(UButton* InButton);
    void EndHold();
    void ButtonUnhovered();
    void ButtonReleased();
    void ButtonPressed();
    void ButtonHovered();
    void BeginHold();
};
