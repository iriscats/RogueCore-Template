#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EnhancementPerkLibrary.generated.h"

class UObject;
class UPerkAsset;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UEnhancementPerkLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UEnhancementPerkLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void SetEquippedEnhancementPerks(const UObject* WorldContext, UPlayerCharacterID* Character, const TArray<UPerkAsset*>& Perks);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TArray<UPerkAsset*> GetUnlockedEnhancementPerks(const UObject* WorldContext);
    static int32 GetTotalNumberOfEnhancementSlots(const UObject* WorldContext);
    static int32 GetNumberOfUnlockedEnhancementSlots(const UObject* WorldContext);
    static TArray<UPerkAsset*> GetEquippedEnhancementPerks(const UObject* WorldContext, UPlayerCharacterID* characterID);
    static int32 GetEnhancementSlotsUnlockRank(const UObject* WorldContext, int32 SlotIndex);
    static int32 GetAmountOfUnlockedEnhancementPerks(const UObject* WorldContext);
    static TArray<UPerkAsset*> GetAllEnhancementPerks(const UObject* WorldContext);
};
