#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "Animation/WidgetAnimation.h"
#include "Blueprint/UMGSequencePlayMode.h"
#include "WidgetAnimationSettings.generated.h"

USTRUCT(BlueprintType)
struct FWidgetAnimationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlaybackSpeed;
    
    TEnumAsByte<EUMGSequencePlayMode::Type> PlayMode;
    bool bRestoreState;
    ROGUECORE_API FWidgetAnimationSettings();
};
