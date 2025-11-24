#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "Templates/SubclassOf.h"
#include "InsectSwarmSpawner.generated.h"

class AActor;
class AInsectSwarmEnemy;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AInsectSwarmSpawner : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AInsectSwarmEnemy> SwarmType;
    
    float SpawnHeightOffset;
    float AlertDistance;
    float respawnDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AInsectSwarmEnemy> SwarmInstance;
    AInsectSwarmSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UStaticMeshComponent* Receive_GetStaticMesh() const;
    void OnSwarmSpawned(AInsectSwarmEnemy* Swarm);
    UFUNCTION(BlueprintCallable)
    void OnSwarmDestroyed(AActor* DestroyedActor);
};
