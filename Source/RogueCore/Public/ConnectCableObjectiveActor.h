#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneratorSpawnData.h"
#include "Templates/SubclassOf.h"
#include "ConnectCableObjectiveActor.generated.h"

class AConnectCableObjectiveSocketActor;
class ATrackBuilderSegment;
class UDebrisPositioning;
class USceneComponent;
class USpawnActorWithDebrisPosComponent;
class UTrackBuilderConnectPoint;
UCLASS(Blueprintable)
class ROGUECORE_API AConnectCableObjectiveActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GeneratorActorToSpawn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ObjectiveCompleted, meta=(AllowPrivateAccess=true))
    bool ObjectiveCompleted;

 
    UDebrisPositioning* DebrisPositioning;
    int32 NumAllowedChecks;
    TArray<FGeneratorSpawnData> GeneratorDistancesPerPlayerCount;
    TSubclassOf<AConnectCableObjectiveSocketActor> SocketActorToSpawnClass;
    int32 MaxFailedSpawns;
    USceneComponent* ChildActorContainer;
    USceneComponent* GeneratorSpawnCenter;
    USpawnActorWithDebrisPosComponent* DebrisSpawner;
    TArray<AActor*> SpawnedGenerators;
    TArray<AConnectCableObjectiveSocketActor*> SocketActors;
    AConnectCableObjectiveActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSocketActorsSpawned();
    UFUNCTION(BlueprintCallable)
    void OnRep_ObjectiveCompleted();
    void OnObjectiveCompleted();
    void OnMatchStarted();
    void OnGeneratorsSpawned();
    void OnGeneratorSpawnTimer();
    void OnConnectedWithSegment(UTrackBuilderConnectPoint* InConnectPoint, ATrackBuilderSegment* InSegment);
};
