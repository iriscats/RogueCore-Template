#pragma once
#include "CoreMinimal.h"
#include "EquippedVanity.generated.h"

class UVanityItem;
USTRUCT(BlueprintType)
struct FEquippedVanity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UVanityItem*> Vanity;
    
    UVanityItem* SelectedArmorMaterial;
    bool UsingSlevedArmor;
    ROGUECORE_API FEquippedVanity();
};
