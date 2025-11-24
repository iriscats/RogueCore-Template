#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EDebrisItemPass.h"
#include "GeneratedDebrisItem.h"
#include "GeneratedInfluenceSets.h"
#include "LevelGenerationCarverLists.h"
#include "PathObstacle.h"
#include "RoomNode.h"
#include "TunnelNode.h"
#include "ProceduralController.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProceduralController : public UActorComponent {
    GENERATED_BODY()
public:
    UProceduralController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RequestTunnelData();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SendTunnelData();
    UFUNCTION(BlueprintCallable)
    void SendRequestedPLSData();
    void SendRequestedCarverData(EDebrisItemPass pass);
    void RequestPLSData();
    void RequestCarverData(EDebrisItemPass pass);
    void ReceivedTunnelData(const TArray<FTunnelNode>& tunnels);
    void ReceivedRoomData(int32 Seed, const TArray<FRoomNode>& Rooms, const TArray<FPathObstacle>& Obstacles);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SendTunnelData(const TArray<FTunnelNode>& tunnels);
    void Client_SendRoomData(int32 Seed, const TArray<FRoomNode>& Rooms, const TArray<FPathObstacle>& Obstacles);
    void Client_RecieveCarverSizes(int32 pass, int32 carverCount);
    void Client_ReceivePLSLevelCarver(int32 pass, const FLevelGenerationCarverLists& levelCarvers);
    void Client_ReceivePLSInfluencers(const FGeneratedInfluenceSets& influenceSet);
    void Client_ReceivePLSDebris(const TArray<FGeneratedDebrisItem>& levelDebris);
};
