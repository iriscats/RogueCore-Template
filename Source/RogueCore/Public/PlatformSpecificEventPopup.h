#pragma once
#include "CoreMinimal.h"
#include "EFSDTargetPlatform.h"
#include "PlatformSpecificEventPopup.generated.h"

class UFSDEventPopupWidget;
USTRUCT(BlueprintType)
struct FPlatformSpecificEventPopup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFSDTargetPlatform TargetPlatform;
    
    TSoftClassPtr<UFSDEventPopupWidget> PopupWidget;
    ROGUECORE_API FPlatformSpecificEventPopup();
};
