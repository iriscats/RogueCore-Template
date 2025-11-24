#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EPickaxePartLocation.h"
#include "PickaxeSet.h"
#include "PickaxeFunctionLibrary.generated.h"

class UItemID;
class UObject;
class UPickaxePart;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UPickaxeFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPickaxeFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool RemovePickaxePartFromOwned(UObject* WorldContextObject, const UPickaxePart* part);
    
    static void RandomizePickaxe(UObject* WorldContextObject, UPlayerCharacterID* PlayerId);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPickaxePartEquipped(UObject* WorldContextObject, EPickaxePartLocation Location, UPickaxePart* part, UItemID* pickaxeID);
    static void GivePickaxePart(UObject* WorldContextObject, UPickaxePart* part);
    static TArray<UPickaxePart*> GetUnlockedPickaxeParts(UObject* WorldContextObject, EPickaxePartLocation Category);
    static TArray<UPickaxePart*> GetPickaxeParts(UObject* WorldContextObject, EPickaxePartLocation Category);
    static bool GetIsPickAxePartAcquired(UObject* WorldContextObject, const UPickaxePart* InPickaxePart);
    static FPickaxeSet GetEquippedPickaxeSet(UObject* WorldContextObject, UItemID* pickaxeID);
    static UPickaxePart* GetEquippedPickaxePart(UObject* WorldContextObject, EPickaxePartLocation partLocation, UItemID* pickaxeID);
    static void EquipPickaxePart(UObject* WorldContextObject, UPickaxePart* part, EPickaxePartLocation partLocation, UItemID* pickaxeID);
    static void CopyPastePickaxeLoadout(UObject* WorldContextObject, UPlayerCharacterID* PlayerId, int32 fromIndex, int32 toIndex);
};
