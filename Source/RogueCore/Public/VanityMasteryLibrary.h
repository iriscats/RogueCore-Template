#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CraftingCost.h"
#include "VanityMasteryResult.h"
#include "VanityMasterySave.h"
#include "VanityMasterySettings.h"
#include "VanityMasteryLibrary.generated.h"

class UObject;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UVanityMasteryLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVanityMasteryLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ResetVanityMasteryXP(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVanityMasterySettings GetVanityMasterySettings();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static FVanityMasterySave GetVanityMasterySave(UObject* WorldContext);
    static int32 GetVanityMasteryFashioniteForLevel(int32 InCurrentLevel);
    static float CalculateVanityMasteryLevelProgress(int32 Level, int32 XP);
    static FVanityMasteryResult AddVanityMasteryXPFromCost(UObject* WorldContext, TArray<FCraftingCost> Cost, UPlayerCharacterID* characterID);
    static FVanityMasteryResult AddVanityMasteryXP(UObject* WorldContext, int32 XP, UPlayerCharacterID* PlayerId);
};
