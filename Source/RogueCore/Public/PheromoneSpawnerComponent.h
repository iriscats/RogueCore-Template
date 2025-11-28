#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandRange.h"
#include "PheromoneSpawnerComponent.generated.h"

class AActor;
class UEnemyDescriptor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPheromoneSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange SpawnInterval;
    
    float AttackPositioningCostModifier;
    UEnemyDescriptor* Enemy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, float> InfectedActors;
    UPheromoneSpawnerComponent(const FObjectInitializer& ObjectInitializer);
};
