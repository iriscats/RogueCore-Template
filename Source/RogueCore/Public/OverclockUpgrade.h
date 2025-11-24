#pragma once
#include "CoreMinimal.h"
#include "CombinedUpgrade.h"
#include "OverclockUpgrade.generated.h"

class USchematicCategory;
UCLASS(Blueprintable, EditInlineNew)
class UOverclockUpgrade : public UCombinedUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicCategory* SchematicCategory;
    
    UOverclockUpgrade();
};
