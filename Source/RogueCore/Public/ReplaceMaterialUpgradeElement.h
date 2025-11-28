#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "ReplaceMaterialUpgradeElement.generated.h"

class UMaterialInterface;
UCLASS(Blueprintable, EditInlineNew)
class UReplaceMaterialUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> TargetMaterial;
    
    TSoftObjectPtr<UMaterialInterface> ReplaceWithMaterial;
    UReplaceMaterialUpgradeElement();
};
