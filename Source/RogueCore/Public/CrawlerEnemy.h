#pragma once
#include "CoreMinimal.h"
#include "CoreSpawnEnemyBase.h"
#include "CrawlerEnemy.generated.h"

class UBallisticMovementComponent;
class UMeleeAttackComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ACrawlerEnemy : public ACoreSpawnEnemyBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBallisticMovementComponent* BallisticMovement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeleeAttackComponent* MeleeAttack;

};
