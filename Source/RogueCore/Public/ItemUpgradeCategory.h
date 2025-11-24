#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "ItemUpgradeCategory.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UItemUpgradeCategory : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryName;
    
    FText CategoryDescription;
    UTexture2D* CategoryIcon;
    FColor CategoryTint;
    UItemUpgradeCategory();
};
