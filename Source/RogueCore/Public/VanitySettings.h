#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "EVanitySlot.h"
#include "ResourceSpawner.h"
#include "VanityMasterySettings.h"
#include "VanitySlotCharacter.h"
#include "VanitySettings.generated.h"

class UDLCBase;
class UObject;
class UPlayerCharacterID;
class UTexture2D;
class UVanityItem;
UCLASS(Blueprintable)
class ROGUECORE_API UVanitySettings : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVanityItem* MedbayArmorItem;
    
    TArray<UVanityItem*> MedbayArmorMaterials;
    UDLCBase* AlwaysLockedDLC;
 
    FVanityMasterySettings MasterySettings;
    FResourceSpawner FashioniteSpawn;
    TArray<UTexture2D*> VanityCategoryIcons;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FGuid> ValidIDs;
    TMap<FGuid, UVanityItem*> ItemMap;
    TMap<EVanitySlot, FVanitySlotCharacter> GlobalItems;
    TMap<EVanitySlot, FVanitySlotCharacter> StoreItems;
    TMap<EVanitySlot, FVanitySlotCharacter> TreassureItems;
    UVanitySettings();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool HasNewVanityNotification(UObject* WorldContextObject, EVanitySlot Slot, UPlayerCharacterID* characterID);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetVanityCategoryIcon(EVanitySlot Slot) const;
    static void GetUnlockedStoreVanityCount(UObject* WorldContextObject, EVanitySlot Slot, UPlayerCharacterID* characterID, int32& owned, int32& Total);
};
