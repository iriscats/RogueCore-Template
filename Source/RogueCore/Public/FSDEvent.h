#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "ClaimableRewardView.h"
#include "EHolidayType.h"
#include "EncounterSpecialItem.h"
#include "FSDEventActivateChangedDelegate.h"
#include "JettyBootEventSettings.h"
#include "PlatformSpecificEventPopup.h"
#include "FSDEvent.generated.h"

class ADebrisDataActor;
class APlayerController;
class UCampaign;
class UDrinkableDataAsset;
class UFSDEvent;
class UFSDEventPopupWidget;
class UObject;
class USoundCue;
class UTexture2D;
class UWorld;
UCLASS(Blueprintable)
class ROGUECORE_API UFSDEvent : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFSDEventActivateChanged OnActiveChanged;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    FName EventName;
    EHolidayType EventType;
    bool bFreeBeerEvent;
    bool bFreeBeerConfettiVisible;
    UDrinkableDataAsset* SpecialEventBeer;
    UTexture2D* SeasonEndScreenImage;
    TSoftObjectPtr<USoundCue> EventAmbienceMusic;
    bool UseDifferentBarLightColor;
    FLinearColor SpaceRigBarLightColor;
    TArray<FEncounterSpecialItem> EventEncounters;
    TArray<TSoftClassPtr<ADebrisDataActor>> EventDebris;
    bool bIsEventDebrisInDeepDives;
    TArray<TSoftObjectPtr<UWorld>> SpacerigSublevels;
    TArray<TSoftObjectPtr<UWorld>> UnloadSpacerigSublevels;
    bool bHasClaimableRewards;
    FClaimableRewardView ClaimableRewards;
    TArray<FPlatformSpecificEventPopup> OptionalPopUpWindow;
    TArray<TSoftClassPtr<UCampaign>> Campaigns;
    TSoftObjectPtr<UTexture2D> TitleScreenOverride;
    FJettyBootEventSettings JettyBootSettings;
    UFSDEvent();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void MarkClaimableRewardsSeen(UObject* WorldContext);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsFsdEventActive(UObject* WorldContext, const UFSDEvent* FSDEvent);
    bool HasUnseenClaimableRewards(UObject* WorldContext);
    UFUNCTION(BlueprintCallable)
    bool GiveRewards(APlayerController* PlayerController);
    UTexture2D* GetTitleScreenOverride();
    bool GetIsActive(UObject* WorldContext) const;
    UFSDEventPopupWidget* CreatePopupWindow(APlayerController* InPlayerController);
};
