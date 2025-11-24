#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "ArmorMaterialVanityItem.generated.h"

class UArmorMaterialVanityItem;
class UArmorVanityItem;
class UDynamicIcon;
class UMaterialInstance;
class UMaterialInstanceConstant;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UArmorMaterialVanityItem : public UVanityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> Material;
    
    TSoftObjectPtr<UMaterialInterface> UndersuitMaterial;
    TSoftObjectPtr<UMaterialInstance> ClothMaterial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDynamicIcon* DynamicIcon;
    UArmorVanityItem* LockedToArmor;
    TArray<UArmorVanityItem*> BannedArmors;
    UArmorMaterialVanityItem();
    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceConstant* SetArmorMaterialToTwoSided(UMaterialInstance* Parent);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInstanceDynamic* CreateIcon(UObject* Owner) const;
    static void CreateClothMaterialForAmorVanity(UArmorMaterialVanityItem* armorVanity);
};
