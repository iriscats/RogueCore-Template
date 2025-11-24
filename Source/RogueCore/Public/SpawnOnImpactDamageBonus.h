#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "Templates/SubclassOf.h"
#include "SpawnOnImpactDamageBonus.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class USpawnOnImpactDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorToSpawn;
    
    USpawnOnImpactDamageBonus();
};
