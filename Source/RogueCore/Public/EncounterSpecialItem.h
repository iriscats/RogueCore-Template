#pragma once
#include "CoreMinimal.h"
#include "EncounterSpecialItem.generated.h"

class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FEncounterSpecialItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* Enemy;
    
    float BaseChance;
    bool CanSpawnInDeepDive;
    ROGUECORE_API FEncounterSpecialItem();
};
