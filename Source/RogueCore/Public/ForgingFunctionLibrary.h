#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ESchematicType.h"
#include "ForgingPendingReward.h"
#include "ForgingResult.h"
#include "ForgingFunctionLibrary.generated.h"

class UObject;
class USchematic;
UCLASS(Blueprintable)
class UForgingFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UForgingFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static USchematic* PickForgingMasteryDefaultReward(UObject* WorldContextObject, ESchematicType InType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FForgingResult GiveForgingXP(UObject* WorldContextObject);
    static TArray<USchematic*> GetOwnedSchematics(UObject* WorldContextObject);
    static void GetForgingPendingMasteryRewardNewest(UObject* WorldContextObject, bool& OutSuccess, FForgingPendingReward& OutReward);
    static ESchematicType GetForgingMasteryRewardType(UObject* WorldContextObject, int32 Level, bool ReturnDefaultIfUnavailable);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ESchematicType GetForgingMasteryRewardDefaultType(ESchematicType InType);
    static float GetForgingLevelProgress(UObject* WorldContextObject);
    static int32 GetForgingLevel(UObject* WorldContextObject);
    static bool GetForgingHasPendingMasteryRewards(UObject* WorldContextObject);
    static TArray<USchematic*> GetForgedSchematics(UObject* WorldContextObject);
    static void ClaimForgingPendingMasteryReward(UObject* WorldContextObject, int32 Level, USchematic* Reward);
};
