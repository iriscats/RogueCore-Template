#pragma once
#include "CoreMinimal.h"
#include "GDItemCategoryIDs.generated.h"

class UCategoryID;
USTRUCT(BlueprintType)
struct FGDItemCategoryIDs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCategoryID* OverclockID;
    
    UCategoryID* ItemSkinID;
    UCategoryID* VanityID;
    UCategoryID* PickaxePartID;
    UCategoryID* WeaponID;
    UCategoryID* CraftingID;
    UCategoryID* ForgeID;
    UCategoryID* BoscoSkinID;
    ROGUECORE_API FGDItemCategoryIDs();
};
