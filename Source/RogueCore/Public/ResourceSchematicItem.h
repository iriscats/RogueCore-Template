#pragma once
#include "CoreMinimal.h"
#include "SchematicItem.h"
#include "ResourceSchematicItem.generated.h"

class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UResourceSchematicItem : public USchematicItem {
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Credits;
    
    UResourceData* Resource;
    int32 ResourceAmount;
    UResourceSchematicItem();
};
