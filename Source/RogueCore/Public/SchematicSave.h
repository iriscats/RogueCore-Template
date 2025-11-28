#pragma once
#include "CoreMinimal.h"

#include "SchematicSave.generated.h"

USTRUCT(BlueprintType)
struct FSchematicSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PendingReward;

    bool bFirstSchematicMessageShown;
    ROGUECORE_API FSchematicSave();
 
    TArray<FGuid> ForgedSchematics;
    TArray<FGuid> OwnedSchematics;
    int32 SkinFixupCounter;
};
