#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedItem.h"
#include "EPlaceableObstructionType.h"
#include "PlaceableInterface.h"
#include "Templates/SubclassOf.h"
#include "TrackBuilderItem.generated.h"

class ATrackBuilderSegment;
class UCrosshairAggregator;
class UTrackBuilderConnectPoint;
class UTrackBuilderUsable;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API ATrackBuilderItem : public AAnimatedItem, public IPlaceableInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCrosshairAggregator* CrosshairAggregator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlaceableObstructionType ObstructionType;
    FVector ObstructionLocation;
    FVector GroundNormal;
    TSubclassOf<ATrackBuilderSegment> DefaultSegmentType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_NextSegment, meta=(AllowPrivateAccess=true))
    ATrackBuilderSegment* NextSegment;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPlacingSegment;
    ATrackBuilderItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdatePlacement(const FTransform& InTransform, UTrackBuilderConnectPoint* InConnectPoint, bool bPlacementValid, bool InUpdateServer);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void ServerUpdatePlacement(const FTransform& InTransform, const bool bPlacementValid, UTrackBuilderConnectPoint* InConnectPoint);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerFinishPlacement(const FTransform& FinalLocation, UTrackBuilderConnectPoint* ConnectPoint);
    void ServerCancelPlacement();
    void ServerBeginPlaceSegment(UTrackBuilderUsable* InUsable);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBeginPlaceSegment();
    UFUNCTION()
    void OnRep_NextSegment();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<ATrackBuilderSegment> GetSegmentType() const;
    void FinishPlacement(const FTransform& FinalLocation, UTrackBuilderConnectPoint* ConnectPoint);
    void CancelPlacement();
    FVector AdjustInitialLocation(const FVector& Location) const;
    // Fix for true pure virtual functions not being implemented
};
