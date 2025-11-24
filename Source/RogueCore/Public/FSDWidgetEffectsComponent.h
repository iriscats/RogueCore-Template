#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CustomCounter.h"
#include "CustomCounterDelegateDelegate.h"
#include "EFSDPingType.h"
#include "EMoveType.h"
#include "WidgetFade.h"
#include "WidgetMover.h"
#include "WidgetPing.h"
#include "WidgetTextCounter.h"
#include "FSDWidgetEffectsComponent.generated.h"

class UObject;
class UTextBlock;
class UUserWidget;
class UWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFSDWidgetEffectsComponent : public UActorComponent {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWidgetPing> WidgetPings;
    
    TArray<FWidgetFade> WidgetFades;
    TArray<FWidgetTextCounter> WidgetTextCounters;
    TArray<FCustomCounter> CustomCounters;
    TArray<FWidgetMover> WidgetMovers;
    UFSDWidgetEffectsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void StartTextCounter(UObject* WorldContext, UTextBlock* Widget, float Start, float End, float Duration, int32 MaxDigits, float StartDelay);
    static void StartCounter(UObject* WorldContext, UObject* Owner, float Start, float End, float Duration, const FCustomCounterDelegate& OnCount, float StartDelay);
    static void PingWidget(UObject* WorldContext, UWidget* Widget, float amount, float Duration, EFSDPingType PingType, float StartDelay);
    static void MoveWidget(UObject* WorldContext, UUserWidget* Widget, FVector2D Start, FVector2D End, float Duration, EMoveType MoveType, float StartDelay);
    static void MoveOutWidget(UObject* WorldContext, UUserWidget* Widget, FVector2D MoveToOffset, float Duration, float StartDelay);
    static void MoveInWidget(UObject* WorldContext, UUserWidget* Widget, FVector2D MoveFromOffset, float Duration, float StartDelay);
    static void FadeWidget(UObject* WorldContext, UUserWidget* Widget, float StartFade, float EndFade, float Duration, float StartDelay);
    static void FadeOutWidget(UObject* WorldContext, UUserWidget* Widget, float Duration, float StartDelay);
    static void FadeInWidget(UObject* WorldContext, UUserWidget* Widget, float Duration, float StartDelay);
};
