#pragma once
#include "CoreMinimal.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "InsectSwarmEnemy.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AInsectSwarmEnemy : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* SwarmParticles;
    
    AInsectSwarmEnemy(const FObjectInitializer& ObjectInitializer);
};
