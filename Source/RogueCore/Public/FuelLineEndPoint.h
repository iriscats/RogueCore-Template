#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "FuelLineEndPoint.generated.h"

class AFuelLineSegment;
class ATrackBuilderSegment;
class UFuelLineConnectPoint;
class UStaticMeshComponent;
class UTrackBuilderConnectPoint;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AFuelLineEndPoint : public AActor {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFuelLineConnectPoint* ConnectPoint;
    
    UStaticMeshComponent* StaticMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFuelLineSegment> AllowedSegment;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool OpenForConnection;
    AFuelLineEndPoint(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOpenForConnection(bool Open);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePing(bool InValidPlacement);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpenForConnection() const;
    UFUNCTION(BlueprintCallable)
    void CallbackConnectedWithSegment(UTrackBuilderConnectPoint* InConnectPoint, ATrackBuilderSegment* InSegment);
};
