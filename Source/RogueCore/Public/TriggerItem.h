#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "TriggerItem.generated.h"

class ASpawnTrigger;
USTRUCT(BlueprintType)
struct FTriggerItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASpawnTrigger> TriggerClass;
    
    FTransform Transform;
    FName Message;
    ROGUECORE_API FTriggerItem();
};
