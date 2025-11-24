#pragma once
#include "CoreMinimal.h"
#include "SchematicBankBase.h"
#include "SchematicBankItem.h"
#include "VictoryPoseSchematicBank.generated.h"

class USchematicCategory;
class UVictoryPose;
UCLASS(Blueprintable)
class ROGUECORE_API UVictoryPoseSchematicBank : public USchematicBankBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicCategory* SchematicCategory;
    
    TMap<UVictoryPose*, FSchematicBankItem> VictoryPoses;
    UVictoryPoseSchematicBank();
};
