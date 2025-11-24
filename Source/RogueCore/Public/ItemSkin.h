#pragma once
#include "CoreMinimal.h"
#include "Aquisitionable.h"
#include "EItemSkinType.h"
#include "SavablePrimaryDataAsset.h"
#include "ItemSkin.generated.h"

class AFSDPlayerState;
class UDynamicIcon;
class UItemAquisitionBase;
class UItemID;
class UItemSkin;
class UItemSkinSet;
class UMaterialInstanceDynamic;
class UObject;
class UPlayerCharacterID;
class USkinEffect;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UItemSkin : public USavablePrimaryDataAsset, public IAquisitionable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FText SkinName;

    UItemSkinSet* SkinSet;

    UDynamicIcon* DynamicIcon;

    USkinEffect* SkinEffect;

    UItemID* OwningItem;

    UPlayerCharacterID* OwningCharacter;

    UItemSkin();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))

    bool Unlock(UObject* WorldContext, UItemID* ItemID, bool broadcast);

    UFUNCTION(BlueprintCallable, BlueprintPure=false)

    void Receive_SkinItem(UObject* Skinnable) const;



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemSkinSignature, UItemSkin*, Skin);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemSkinEquipSignature, const UItemSkin*, Skin);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FItemSkinSignature OnSkinUnlocked;
    FItemSkinEquipSignature OnSkinEquipped;
    FItemSkinEquipSignature OnSkinUnequipped;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemAquisitionBase* Aquisition;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SkinName;
    UItemSkinSet* SkinSet;
    UDynamicIcon* DynamicIcon;
    USkinEffect* SkinEffect;
    UItemID* OwningItem;
    UPlayerCharacterID* OwningCharacter;
    UItemSkin();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool Unlock(UObject* WorldContext, UItemID* ItemID, bool broadcast);
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void Receive_SkinItem(UObject* Skinnable) const;
    void Lock(UObject* WorldContext, UItemID* ItemID);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnlockedFromStart() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsLocked(UObject* WorldContext, UItemID* skinnableID) const;
    bool IsEquippedOnItem(UItemID* ItemID, AFSDPlayerState* PlayerState) const;
    EItemSkinType GetSkinType() const;
    FText GetSkinName() const;
    UItemID* GetOwningItem() const;
    UPlayerCharacterID* GetOwningCharacter() const;
    UMaterialInstanceDynamic* CreateIcon(UObject* Owner) const;
    // Fix for true pure virtual functions not being implemented
};
