#pragma once
#include "CoreMinimal.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "CoreSpawnEnemyBase.generated.h"

class UDeathFXComponent;
class UEnemyComponent;
class UHitReactionComponent;
class UOutlineComponent;
class UPawnAlertComponent;
class UPawnSensingComponent;
class UPawnStatsComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ACoreSpawnEnemyBase : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LimitRagdollSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnStatsComponent* PawnStats;

 
    float MaxRagdollSpeed;
    UHitReactionComponent* HitReactions;
    UPawnSensingComponent* PawnSensing;
    UEnemyComponent* Enemy;
    UOutlineComponent* Outline;
    UPawnAlertComponent* PawnAlert;
    UDeathFXComponent* Death;
    ACoreSpawnEnemyBase(const FObjectInitializer& ObjectInitializer);
};
