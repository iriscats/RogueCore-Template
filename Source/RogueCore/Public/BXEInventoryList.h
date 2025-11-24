#pragma once
#include "CoreMinimal.h"
#include "InventoryList.h"
#include "BXEInventoryList.generated.h"

class UBXEStartingWeapon;
class UItemID;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEInventoryList : public UInventoryList {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UBXEStartingWeapon*> StartingWeapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemID*> UnlockItems;
    UBXEInventoryList();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UBXEStartingWeapon*> GetStartingWeapons() const;
    TArray<UItemID*> GetStartingItems() const;
};
