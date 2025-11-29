#pragma once
#include "CoreMinimal.h"
#include "GamepadCursorSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UGamepadCursorSettings : public UDeveloperSettings {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    float Acceleration;
    float StickySlowDown;
    float DeadZone;
    UGamepadCursorSettings();
};
