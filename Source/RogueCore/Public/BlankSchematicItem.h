#pragma once
#include "CoreMinimal.h"
#include "SchematicItem.h"
#include "BlankSchematicItem.generated.h"

class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class UBlankSchematicItem : public USchematicItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText Description;
    UTexture2D* Icon;
    UBlankSchematicItem();
};
