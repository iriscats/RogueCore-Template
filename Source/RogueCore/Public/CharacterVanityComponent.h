#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EHeadVanityType.h"
#include "EVanitySlot.h"
#include "EquippedVanity.h"
#include "TattooArmorItem.h"
#include "CharacterVanityComponent.generated.h"

class UArmorMaterialVanityItem;
class UBeardColorVanityItem;
class UCharacterVanityItems;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UPlayerCharacterID;
class USkeletalMeshComponent;
class UVanityItem;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterVanityComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBeardColorVanityItem* ShownBeardColor;
    
    UMaterialInterface* ArmorMaterial;
    UMaterialInterface* UndersuitMaterial;
    UMaterialInterface* ArmorClothMaterial;
    UMaterialInstanceDynamic* DynamicSkinMaterial;
    EHeadVanityType HeadVanityType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EquippedVanity, meta=(AllowPrivateAccess=true))
    FEquippedVanity EquippedVanity;
    UVanityItem* PreviewedItem;
    UArmorMaterialVanityItem* PreviewedArmorMaterial;
    UMaterialInterface* SkinMaterial;
    TArray<FTattooArmorItem> Tattoos;
    TArray<UMaterialInterface*> CachedMaterials;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<EVanitySlot, USkeletalMeshComponent*> VanityMeshes;
    UCharacterVanityComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateMeshes();
    void UpdateEquippedVanity(bool applyItems);
    void SetEquippedVanityInViewer(const FEquippedVanity& equippedVanityItems);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDesireSleevelessArmor(UObject* WorldContextObject, UPlayerCharacterID* Character, bool inDesireSleeveless);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetEquippedVanity(const FEquippedVanity& EquippedItems);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveMedicalGown();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UVanityItem* Receive_GetEquippedVanityItem(UObject* WorldContextObject, UPlayerCharacterID* Character, EVanitySlot Slot);
    static bool Receive_GetDesireSleevelessArmor(UObject* WorldContextObject, UPlayerCharacterID* Character);
    UFUNCTION()
    void OnRep_EquippedVanity();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool HasSpawnedInMedbay() const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVanityItem* GetEquippedVanityItem(EVanitySlot Slot, bool ignorePreviewItems) const;
    bool GetDesireSleevelessArmor() const;
    UCharacterVanityItems* GetAvailableVanityItems() const;
    void EquipMedicalGown();
    void EnforceValidPaintjob();
    void CreateEquippedGear();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_RemoveMedicalGown();
    void Client_EquipMedicalGown_Implementation();
};
