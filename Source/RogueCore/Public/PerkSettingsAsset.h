#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PerkSettings.h"
#include "PerkSettingsAsset.generated.h"

UCLASS(Blueprintable)
class UPerkSettingsAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerkSettings Perks;
    
    UPerkSettingsAsset();
};
