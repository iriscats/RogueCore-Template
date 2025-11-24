#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Layout/Margin.h" 
#include "FSDUserWidget.h"
#include "Templates/SubclassOf.h"
#include "ActorTrackingWidget.generated.h"

class AActor;
class APlayerController;
class UActorTrackingWidget;
class USceneComponent;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UActorTrackingWidget : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> TargetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorldHeightOffset;
    float ScaleBy;
    FMargin ScreenMargin;
    int32 WidgetZOrder;
    bool bTrackCenterOfMass;
    bool bHideWhenPlayerNearby;
    bool bHideWhenPlayerFarAway;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastTargetDistanceUpdate;
    UActorTrackingWidget();
    UFUNCTION(BlueprintCallable)
    void SetTargetComponent(USceneComponent* Component);
    void SetTarget(AActor* Actor);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTargetSet(AActor* NewTarget);
    void OnTargetDistanceChanged(float Distance);
    void OnShow();
    void OnInViewChanged(bool inView, float Angle);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget() const;
    FVector2D GetRenderTranslation() const;
    static bool FindScreenPosition(APlayerController* PlayerController, FVector WorldLocation, FMargin Margin, FVector& ScreenCord, float& Angle);
    static UActorTrackingWidget* CreateTrackingWidget(APlayerController* PlayerController, TSubclassOf<UActorTrackingWidget> WidgetType, USceneComponent* NewTargetComponent);
};
