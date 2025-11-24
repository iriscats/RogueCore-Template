#pragma once
#include "CoreMinimal.h"
#include "FSDUserWidget.h"
#include "AngleIndicatorWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAngleIndicatorWidget : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float pixelsPerAngle;
    
    float AlphaFade;
    float MinAngle;
    float MaxAngle;
    UAngleIndicatorWidget();
};
