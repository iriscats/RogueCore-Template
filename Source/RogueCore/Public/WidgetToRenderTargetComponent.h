#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "WidgetToRenderTargetComponent.generated.h"

class ULocalPlayer;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTextureRenderTarget2D;
class UUserWidget;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWidgetToRenderTargetComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> WidgetClass;
    
    FIntPoint DrawSize;
    bool bManuallyRedraw;
    bool bRedrawRequested;
    float RedrawTime;
    float LastWidgetRenderTime;
    bool bWindowFocusable;
    FIntPoint CurrentDrawSize;
    bool bDrawAtDesiredSize;
    FVector2D Pivot;
    UMaterialInterface* BaseMaterial;
    ULocalPlayer* OwnerPlayer;
    FLinearColor BackgroundColor;
    FLinearColor TintColorAndOpacity;
    float OpacityFromTexture;
    bool bIsTwoSided;
    bool TickWhenOffscreen;
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUserWidget* Widget;
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RenderTarget;
    UMaterialInstanceDynamic* MaterialInstance;
    bool bEditTimeUsable;
    UWidgetToRenderTargetComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetWidget(UUserWidget* NewWidget);
    void SetOwnerPlayer(ULocalPlayer* LocalPlayer);
    void SetBackgroundColor(const FLinearColor NewBackgroundColor);
    void RequestRedraw();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUserWidget* GetUserWidgetObject() const;
    UTextureRenderTarget2D* GetRenderTarget() const;
    ULocalPlayer* GetOwnerPlayer() const;
    UMaterialInstanceDynamic* GetMaterialInstance() const;
};
