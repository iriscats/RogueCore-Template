#pragma once
#include "CoreMinimal.h"
#include "Aquisitionable.h"
#include "Craftable.h"
#include "CraftingCost.h"
#include "EVanitySlot.h"
#include "RefundableInterface.h"
#include "SavablePrimaryDataAsset.h"
#include "VanityEventSource.h"
#include "VanityItem.generated.h"

class AFSDPlayerState;
class APlayerCharacter;
class UCharacterVanityComponent;
class UIconGenerationCameraKey;
class UItemAquisitionBase;
class UObject;
class UPlayerCharacterID;
class UTexture;
class UVanityEventSourceDataAsset;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UVanityItem : public USavablePrimaryDataAsset, public ICraftable, public IRefundableInterface, public IAquisitionable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ItemName;
    
    FText ItemDescription;
    FString NotesInternal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemAquisitionBase* Aquisition;
    UVanityEventSourceDataAsset* EventSourceAsset;
    UIconGenerationCameraKey* IconGenerationCameraKey;
    TSet<UPlayerCharacterID*> RestrictToCharacters;
    UVanityItem();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool RemoveFromOwned(UObject* WorldContext);
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PreviewItem(AFSDPlayerState* PlayerState, bool Show) const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool IsOwned(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    bool IsEquipped(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEventSource() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void GiftItem(UObject* WorldContextObject, UPlayerCharacterID* characterID);
    EVanitySlot GetVanitySlot() const;
    TArray<FCraftingCost> GetResourceCost() const;
    int32 GetRequiredPlayerRank() const;
    bool GetIsUnLockedFromStart() const;
    UTexture* GetIcon() const;
    FCraftingCost GetFashioniteCost() const;
    FVanityEventSource GetEventSource() const;
    int32 GetCraftingCreditsCost() const;
    FText GetCraftableName() const;
    FText GetCraftableDescription() const;
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
    void CraftItemWithFashionite(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    void CraftItem(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    UFUNCTION(BlueprintCallable)
    void ChangeToItem(UCharacterVanityComponent* Gear) const;
    bool CanCraftWithFashionite(UObject* WorldContextObject) const;
    bool CanCraft(UObject* WorldContextObject) const;
    void ApplyItemPermanently(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    void ApplyItem(APlayerCharacter* Player, bool isPermanent) const;
    // Fix for true pure virtual functions not being implemented
};
