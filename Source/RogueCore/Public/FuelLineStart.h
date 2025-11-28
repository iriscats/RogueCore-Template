#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FuelLineStart.generated.h"

class AFuelLineEndPoint;
class AFuelLineSegment;
class ATrackBuilderSegment;
class UFuelLineStartUsable;
class UOutlineComponent;
class USimpleObjectInfoComponent;
class UStaticMeshComponent;
class UTrackBuilderUsable;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AFuelLineStart : public AActor {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuelLineStartedDelegate, bool, InFuelLineStarted);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuelLineConnectedDelegate, AFuelLineEndPoint*, InFuelLineStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFirstFuelLineDelegate, AFuelLineSegment*, InFirstSegment);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFuelLineConnectedDelegate OnFuelLineConnected;
    FFuelLineStartedDelegate OnFuelLineStarted;
    FFirstFuelLineDelegate OnFirstFuelLineSegment;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    UOutlineComponent* OutlineComponent;
    USimpleObjectInfoComponent* ObjectInfoComponent;
    UFuelLineStartUsable* UsableStartFuelLine;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FuelLineConnected, meta=(AllowPrivateAccess=true))
    bool bFuelLineConnected;
    AFuelLineStart(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveFuelLineConnected();
    UFUNCTION(BlueprintCallable)
    void OnRep_FuelLineConnected();
    void CallbackNextSegmentChanged(UTrackBuilderUsable* InUsable, ATrackBuilderSegment* InSegment);
};
