#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/PlayerInput.h"
#include "InputCoreTypes.h"
#include "Input/Events.h"
#include "EFSDInputSource.h"
#include "InputDisplay.h"
#include "InputFunctionLibrary.generated.h"

class APlayerController;
class UTexture2D;
UCLASS(Blueprintable)
class UInputFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UInputFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetMouseSmoothingOn(bool smoothingOn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMouseSmoothingOn();
    static bool IsMouseEventAction(const FPointerEvent& MouseEvent, const FName& ActionName, bool IgnoreCustomBindings);
    static bool IsKeyEventActionAny(const FKeyEvent& KeyEvent, TArray<FName> ActionNames, bool IgnoreCustomBindings);
    static bool IsKeyEventAction(const FKeyEvent& KeyEvent, FName ActionName, bool IgnoreCustomBindings);
    static bool IsInputActionDown(const APlayerController* InPlayerController, FName InActionName);
    static bool IsAxisMappedToDirectional(FName InActionName, FKey Key, int32 Direction, bool IgnoreCustomBindings);
    static bool IsAnyInputActionDown(const APlayerController* InPlayerController, const TArray<FName>& InActionNames);
    static bool IsActionMappedTo(FName InActionName, FKey Key, bool IgnoreCustomBindings);
    static bool GetAxisMapping(FName InActionName, int32 Axis, bool InGamepadKeys, FInputAxisKeyMapping& OutResult);
    static bool GetActionMapping(FName InActionName, bool InGamepadKeys, FInputActionKeyMapping& OutResult);
    static bool FindInputDisplay(const APlayerController* PlayerController, FName InputName, EFSDInputSource InputSource, int32 LayoutIndex, FInputDisplay& OutInputDisplay);
    static UTexture2D* FindActionIcon(FName InActionName, bool InGamepadKeys);
};
