#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConnectCableObjectiveSocketActor.generated.h"

class ATrackBuilderSegment;
class UChildActorComponent;
class USceneComponent;
class UStaticMeshComponent;
class UTrackBuilderConnectPoint;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AConnectCableObjectiveSocketActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool IsDisabled;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;

 
    UStaticMeshComponent* SocketMesh;
    UChildActorComponent* FuelLineEndPoint;
    AConnectCableObjectiveSocketActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisabled();
    UFUNCTION(BlueprintCallable)
    void OnConnectedWithSegment(UTrackBuilderConnectPoint* InConnectPoint, ATrackBuilderSegment* InSegment);
    void OnCableConnected();
};
