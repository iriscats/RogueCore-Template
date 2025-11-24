#pragma once
#include "CoreMinimal.h"
#include "EItemCategory.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "ItemID.generated.h"

class AActor;
class AItem;
class UItemData;
class UItemSkin;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class ROGUECORE_API UItemID : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> Item;
    
    UPlayerCharacterID* ItemOwner;
    EItemCategory ItemCategory;
    UItemID();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsItemClassChildOf(TSubclassOf<AActor> InParentClass) const;
    UItemData* GetItemData() const;
    TSubclassOf<AItem> GetItemClass() const;
    EItemCategory GetItemCategory() const;
    AItem* GetItem() const;
    UFUNCTION(BlueprintCallable)
    TArray<UItemSkin*> GetAllSkins();
    TSubclassOf<AActor> GetActorClass() const;
    AActor* GetActor() const;
};
