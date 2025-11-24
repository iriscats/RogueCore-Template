#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SchematicBlueprintLibrary.generated.h"

class UItemSkinSchematicCollection;
class UItemUpgrade;
class UObject;
class UPlayerCharacterID;
class USchematic;
class USchematicCategory;
UCLASS(Blueprintable)
class USchematicBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USchematicBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void PriceSchematics(const TSet<USchematic*>& Schematics);
    
    static void PriceAllSchematics(bool lockPrices);
    static void LockSchematics(const TSet<USchematic*>& Schematics);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool HasAnyUnlockableSchematics(UObject* WorldContextObject, UPlayerCharacterID* characterID, TSet<USchematicCategory*>& Categories);
    static USchematicCategory* FindItemUpgradeSchematicCategory(UItemUpgrade* upgrade);
    static void AddSkinSchematicCollectionToSettings(UItemSkinSchematicCollection* Collection);
};
