#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "ESchematicType.h"
#include "SchematicType.h"
#include "SchematicSettings.generated.h"

class UDataTable;
class UItemID;
class UItemSkinSchematicCollection;
class UOverclockBank;
class USchematic;
class USchematicBank;
class USchematicBankBase;
class USchematicCategory;
class USchematicPricingTier;
class USchematicRarity;
UCLASS(Blueprintable)
class USchematicSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* PricingTable;
    
    USchematic* BlankSchematic;
    TSet<USchematicBank*> SchematicBanks;
    TSet<UOverclockBank*> OverclockBanks;
    TSet<UItemSkinSchematicCollection*> SkinSchematicCollections;
    TSet<USchematicBankBase*> VanitySchematicBanks;
    TMap<ESchematicType, FSchematicType> SchematicTypes;
    USchematicBank* EndlessSchematics;
    TSet<USchematicCategory*> Categories;
    TArray<USchematicCategory*> OverclockCategories;
    TArray<USchematicCategory*> VanityCategories;
    TArray<USchematicCategory*> EndlessCategories;
    USchematicPricingTier* OverclockPricingTier;
    TArray<USchematicPricingTier*> VanityPricingTiers;
    TArray<USchematicRarity*> VanityRarity;
    TArray<USchematicRarity*> OverclockRarity;
    TArray<USchematicRarity*> EndlessRarity;
    USchematicCategory* VanityCatHeadWear;
    USchematicCategory* VanityCatMoustache;
    USchematicCategory* VanityCatBeard;
    USchematicCategory* VanityCatArmor;
    USchematicCategory* VanityCatEyebrow;
    USchematicCategory* VanityCatHairColor;
    USchematicCategory* VanityCatSideburn;
    USchematicCategory* VanityCatSkinColor;
    USchematicCategory* VanityCatVictoryPose;
    USchematicCategory* WeaponPaintJob;
    UDataTable* SchematicGATable;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, USchematic*> AllSchematicsMap;
    TSet<USchematic*> AllSchematics;
    USchematicSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ValidateVanitySchematics() const;
    FSchematicType GetSchematicTypeData(ESchematicType InType);
    UFUNCTION(BlueprintCallable)
    TSet<USchematic*> GetSchematics() const;
    UOverclockBank* GetOverclocksForItem(UItemID* Item) const;
};
