#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ActionIconMapping.h"
#include "InputTranslationTable.h"
#include "ControllerIconSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UControllerIconSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputTranslationTable InputTranslationTable;
    
protected:
    TArray<FActionIconMapping> Xbox_KeyIcons;
    TArray<FActionIconMapping> Playstation_KeyIcons;
    TArray<FActionIconMapping> Playstation5_KeyIcons;
    TArray<FActionIconMapping> MouseKeyboard_KeyIcons;
    UControllerIconSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool FindMouseKeyboardKeyIcon(FKey Key, FActionIconMapping& KeyIcon);
    static bool FindKeyIcon(FKey Key, FActionIconMapping& KeyIcon);
    static bool FindControllerKeyIcon(FKey Key, FActionIconMapping& KeyIcon);
};
