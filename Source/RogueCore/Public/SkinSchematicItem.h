#pragma once
#include "CoreMinimal.h"
#include "SchematicItem.h"
#include "SkinSchematicItem.generated.h"

class UItemID;
class UItemSkin;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API USkinSchematicItem : public USchematicItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* ItemID;
    
    UItemSkin* Skin;
    USkinSchematicItem();
};
