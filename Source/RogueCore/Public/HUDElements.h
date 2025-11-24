#pragma once
#include "CoreMinimal.h"
#include "HUDElementData.h"
#include "HUDElements.generated.h"

USTRUCT(BlueprintType)
struct FHUDElements {
    GENERATED_BODY()
public:
    FHUDElements();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHUDElementData OnScreenHelp;

    FHUDElementData EnemyHealth;
    FHUDElementData RadarDepth;
    FHUDElementData PlayerHealthShield;
    FHUDElementData PlayerNameClassIcon;
    FHUDElementData PlayerItems;
    FHUDElementData PlayerResources;
    FHUDElementData WeaponInfo;
    FHUDElementData Grenades;
    FHUDElementData FlashLight;
    FHUDElementData Flares;
    FHUDElementData Crosshair;
    FHUDElementData Objectives;
    FHUDElementData TeamDisplay;
    FHUDElementData SentryGunDisplay;
    FHUDElementData VersionNumber;
    FHUDElementData HostileReading;
    FHUDElementData ExpeniteBar;
    FHUDElementData Unlocks;
    FHUDElementData PostEntrance;

};

