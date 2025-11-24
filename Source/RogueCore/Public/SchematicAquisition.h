#pragma once
#include "CoreMinimal.h"
#include "ItemAquisitionBase.h"
#include "SchematicAquisition.generated.h"

class USchematic;
class USchematicPricingTier;
class USchematicRarity;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API USchematicAquisition : public UItemAquisitionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicPricingTier* PricingTier;
    
    USchematicRarity* Rarity;
    TArray<USchematic*> Schematics;
    USchematicAquisition();
};
