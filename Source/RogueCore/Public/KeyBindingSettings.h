#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CustomKeySetting.h"
#include "KeyBindingSettings.generated.h"

UCLASS(Blueprintable)
class UKeyBindingSettings : public UDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCustomKeySetting> KeyboardMouseButtons;
    
    TArray<FCustomKeySetting> ControllerButtons;
    UKeyBindingSettings();
};
