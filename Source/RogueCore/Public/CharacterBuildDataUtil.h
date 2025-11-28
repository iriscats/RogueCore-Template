#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "BXEUnlockInstance.h"
#include "UnlockableItemData.h"
#include "WeaponOverviewAttribute.h"
#include "CharacterBuildDataUtil.generated.h"

class UBXEUnlockBase;
UCLASS(Blueprintable)
class ROGUECORE_API UCharacterBuildDataUtil : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, UBXEUnlockBase*> AllUnlocks;
    
    UCharacterBuildDataUtil();
    UFUNCTION(BlueprintCallable)
    static void GetWeaponOverviewAttributes(const FUnlockableItemData& Item, TArray<FWeaponOverviewAttribute>& OutAttributes);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    TArray<FBXEUnlockInstance> GetCooperUpgrades(const UObject* WorldContextObject);
};
