#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Templates/SubclassOf.h"
#include "ActorTrackingComponent.generated.h"

class UActorTrackingWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorTrackingComponent : public USceneComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorTrackingWidget> WidgetType;
    
    bool VisibleOnHoldTAB;
    bool VisibleFromStart;
    bool bIconHidden;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorTrackingWidget> Widget;
    UActorTrackingComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleIcon(bool visible);
    void ShowAlwaysOn();
    void OnHoldTAB(bool IsDown);
};
