#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "CharacterSettings.generated.h"

class ACarriableItem;
class APlayerCharacter;
class UCampaignManager;
class UCharacterVanityItems;
class UDebrisPositioning;
class UDialogDataAsset;
class UInventoryList;
class UPlayerCharacterData;
class UPlayerCharacterID;
class UTerrainPlacementComponent;
class UUseAnimationSetting;
UCLASS(Blueprintable)
class UCharacterSettings : public UDataAsset {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<APlayerCharacter>> RankedHeroClasses;

    TArray<UPlayerCharacterID*> ExcludedPlayerCharacterIDs;
    TArray<FText> PlayerRankNames;
    TArray<int32> CharacterXPLevels;
    TMap<FGuid, UPlayerCharacterID*> PlayerCharacterIDMap;
    TArray<UPlayerCharacterID*> PlayerCharacterIDs;
    UPlayerCharacterID* BoscoID;
    UPlayerCharacterID* DefaultCharacterID;
    UPlayerCharacterID* DefaultEditorCharacterID;
    TSoftClassPtr<ACarriableItem> CarriableBagClass;
    UUseAnimationSetting* ThrowItemAnimSettings;
    TSoftClassPtr<UCampaignManager> CampaignManagerClass;
    TMap<UPlayerCharacterID*, UCharacterVanityItems*> CharacterVanityItems;
    UDialogDataAsset* AutoReloadShout;
    UDebrisPositioning* TeleportPositioning;
    TSubclassOf<UTerrainPlacementComponent> TeleportPlacement;
    TSoftClassPtr<APlayerCharacter> MockPlayerCharacter;

    UCharacterSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerCharacterID* GetPlayerCharacterID(const FGuid& ID) const;

    UInventoryList* GetInventoryList() const;

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, UPlayerCharacterData*> CharacterData;
};
