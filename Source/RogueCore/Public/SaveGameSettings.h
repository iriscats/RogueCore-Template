#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "SaveGameSettings.generated.h"

class UVanityItem;
UCLASS(Blueprintable)
class USaveGameSettings : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, UVanityItem*> CampaignVanityFixupList;
    
    USaveGameSettings();
};
