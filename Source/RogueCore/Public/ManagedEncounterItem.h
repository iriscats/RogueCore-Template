#pragma once
#include "CoreMinimal.h"
#include "ManagedEncounterItem.generated.h"

class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FManagedEncounterItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* descriptor;
    
    int32 amount;
    ROGUECORE_API FManagedEncounterItem();
};
