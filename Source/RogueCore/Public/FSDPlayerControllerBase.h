#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerController.h"
#include "EDisconnectReason.h"
#include "EHUDVisibilityReason.h"
#include "EMinersManualSection.h"
#include "EMinersManualSinglePage.h"
#include "LocalVoiceStatusDelegate.h"
#include "OnClientKickedDelegate.h"
#include "PlatformComponent.h"
#include "FSDPlayerControllerBase.generated.h"

class UEscapeMenuWindow;
class UMaterialParameterCollection;
class UPlayerCharacterID;
class UWindowManager;
UCLASS(Blueprintable, NoExport, Config=Engine)
class AFSDPlayerControllerBase : public APlayerController {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnClientKicked OnClientKicked;
    
    UMaterialParameterCollection* GlobalMaterialParameterCollection;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalVoiceStatus OnPlayerVoiceStatusChanged;
protected:
    bool bStartWithBlackScreen;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindowManager* WindowManager;
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlatformComponent> PlatformComponentClasses;
    AFSDPlayerControllerBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleAnalogCursor(bool visible);
    void StoreCharacter();
    void StopAspectRatioAxisConstraint();
    void StartAspectRatioAxisConstraint();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowEscapeMenu();
    void SetHUDVisible(bool IsVisible, EHUDVisibilityReason reason);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Cheat_SwitchCharacter(UPlayerCharacterID* newCharacter);
    void RecievePreClientTravel();
    void RecieveHUDVisibilityChanged(bool IsVisible);
    void OpenStandaloneMinersManualPage(EMinersManualSinglePage page);
    void OpenStandaloneMinersManual(EMinersManualSection Section, const FGuid& ID);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerBlocked(const FString& UserId);
    bool IsHUDVisibleFlagSet(EHUDVisibilityReason reason);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UEscapeMenuWindow* GetEscapeMenu() const;
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_WasKicked(EDisconnectReason reason);
};
