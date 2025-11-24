#pragma once
#include "CoreMinimal.h"
#include "SchematicBankItem.generated.h"

class USchematic;
class USchematicPricingTier;
class USchematicRarity;
USTRUCT(BlueprintType)
struct FSchematicBankItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicPricingTier* PricingTier;
    
    USchematicRarity* Rarity;
    TArray<USchematic*> Schematics;
    ROGUECORE_API FSchematicBankItem();
};
