#pragma once
#include "CoreMinimal.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "InsectSwarmEnemy.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable)
class AInsectSwarmEnemy : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* SwarmParticles;
    
    AInsectSwarmEnemy(const FObjectInitializer& ObjectInitializer);
};
