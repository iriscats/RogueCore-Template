#pragma once
#include "CoreMinimal.h"
#include "ETurn180Mode.h"
#include "ControllerSettings.generated.h"

USTRUCT(BlueprintType)
struct FControllerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimInnerDeadZone;
    
    float AimSensitivity;
    float AimOuterAcceleration;
    ETurn180Mode Turn180Mode;
    bool bPreviousItemEnabled;
    bool bChatEnabled;
    ROGUECORE_API FControllerSettings();
};
