#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EHUDVisibilityReason.h"
#include "FSDHUD.generated.h"

class AFSDHUD;
class APlayerCameraDrone;
class APlayerCharacter;
class APlayerController;
class UFSDMainHUDWidget;
class URadarPointComponent;
UCLASS(Blueprintable, NoExport, NonTransient)
class AFSDHUD : public AHUD {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSetObjectivesVisible, bool, inVisible, bool, animate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHudVisibilityChanged, bool, InHudVisible);
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSetObjectivesVisible SetObjectivesVisible;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHudVisibilityChanged OnHUDVisibilityChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 IsVisibleFlags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFSDMainHUDWidget* HUDWidget;
    AFSDHUD(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool ToggleHUDVisibility(EHUDVisibilityReason reason);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowObjectives(bool InVisibility);
    void SetHUDWidget(UFSDMainHUDWidget* InWidget);
    void SetHUDVisible(bool IsVisible, EHUDVisibilityReason reason);
    void ReceiveResetHUD();
    void RadarPointAdded(URadarPointComponent* radarPoint);
    void PlayerSpawned(APlayerCharacter* Player);
    void OnVisibilityChanged();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHUDVisibleFlagSet(EHUDVisibilityReason reason) const;
    void HandleSeamlessTravel();
    UFSDMainHUDWidget* GetHUDWidget();
    bool GetHUDVisible() const;
    static AFSDHUD* GetFSDHUD(APlayerController* InPlayerController);
    void CameraDroneSpawned(APlayerCameraDrone* drone);
};
