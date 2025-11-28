#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EItemSkinCollectionType.h"
#include "ItemSkinSchematicCollection.generated.h"

class UItemSkin;
class USchematic;
class USchematicCategory;
class USchematicPricingTier;
class USchematicRarity;
UCLASS(Blueprintable)
class ROGUECORE_API UItemSkinSchematicCollection : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemSkin* Skin;
    
    USchematicCategory* Category;
    USchematicPricingTier* PricingTier;
    USchematicRarity* Rarity;
    EItemSkinCollectionType CollectionType;
    EItemSkinCollectionType LastGeneratedCollectionType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USchematic*> Schematics;
    UItemSkinSchematicCollection();
};
