#pragma once
#include "CoreMinimal.h"
#include "SchematicItem.h"
#include "VictoryPoseSchematicItem.generated.h"

class UVictoryPose;
UCLASS(Blueprintable, EditInlineNew)
class UVictoryPoseSchematicItem : public USchematicItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVictoryPose* VictoryPose;
    
    UVictoryPoseSchematicItem();
};
