#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockBase.h"
#include "BXEUnlockItem.generated.h"

class UItemID;
UCLASS(Blueprintable)
class UBXEUnlockItem : public UBXEUnlockBase {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* ItemID;
    
    FText DisplayText;
    bool IsStartingWeapon;
    UBXEUnlockItem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetItemName() const;
    bool GetIsGrenadeItem() const;
};
