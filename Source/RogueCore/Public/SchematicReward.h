#pragma once
#include "CoreMinimal.h"
#include "ESchematicType.h"
#include "UnlockReward.h"
#include "SchematicReward.generated.h"

class USchematic;
UCLASS(Blueprintable, EditInlineNew)
class USchematicReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESchematicType SchematicType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USchematic* RewardedSchematic;
    USchematicReward();
};
