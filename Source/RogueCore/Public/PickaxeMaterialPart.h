#pragma once
#include "CoreMinimal.h"
#include "PickaxePartItem.h"
#include "PickaxeMaterialPart.generated.h"

class UDynamicIcon;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UPickaxeMaterialPart : public UPickaxePartItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDynamicIcon* DynamicIcon;
    UPickaxeMaterialPart();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInstanceDynamic* CreateIcon(UObject* Owner) const;
};
