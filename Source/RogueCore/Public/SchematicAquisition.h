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
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicPricingTier* PricingTier;
    
    USchematicRarity* Rarity;
    TArray<USchematic*> Schematics;
    USchematicAquisition();
};
