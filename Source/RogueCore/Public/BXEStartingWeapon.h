#pragma once
#include "CoreMinimal.h"
#include "BXEStartingWeaponMissionStats.h"
#include "EUnlockableState.h"
#include "SavableDataAsset.h"
#include "UnlockableObject.h"
#include "BXEStartingWeapon.generated.h"

class UBXEChallenge;
class UBXEUnlockItem;
class UItemData;
class UItemID;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEStartingWeapon : public USavableDataAsset, public IUnlockableObject {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEUnlockItem* UnlockAsset;
    
    UBXEChallenge* UnlockChallenge;
    FBXEStartingWeaponMissionStats MissionStats;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemID* LoadedItemID;
    UBXEStartingWeapon();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetWeaponName() const;
    FText GetWeaponDescription() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    FText GetUnlockChallengeText(const UObject* WorldContext) const;
    UBXEChallenge* GetUnlockChallenge() const;
    UBXEUnlockItem* GetUnlockAsset() const;
    UItemID* GetItemID() const;
    UItemData* GetItemData() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool Equip(const UObject* WorldContext);
    // Fix for true pure virtual functions not being implemented
    bool Unlock(const UObject* WorldContext) override PURE_VIRTUAL(Unlock, return false;);
    TEnumAsByte<EUnlockableState> GetUnlockableState(const UObject* WorldContext) const override PURE_VIRTUAL(GetUnlockableState, return Unlockable;);
};
