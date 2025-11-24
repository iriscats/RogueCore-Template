#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ETrackBuildPlacementState.h"
#include "TrackBuilderPoint.h"
#include "TrackBuilderSegment.generated.h"

class AItem;
class APlayerCharacter;
class ATrackBuilderSegment;
class UTrackBuilderConnectPoint;
class UTrackBuilderUsable;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATrackBuilderSegment : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentEndTransform, meta=(AllowPrivateAccess=true))

    FTrackBuilderPoint ServerSegmentEndTransform;

    ATrackBuilderSegment(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrackBuilderUsable* NextSegmentUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> BuiltByCharacter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrackBuilderUsable> BuiltFromUsable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTrackBuilderPoint SegmentEndTransform;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentEndTransform, meta=(AllowPrivateAccess=true))
    FTrackBuilderPoint ServerSegmentEndTransform;
    ATrackBuilderSegment(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool UpdatePlacement(const FTransform& InTransform, UTrackBuilderConnectPoint* InConnectPoint, bool InPlacementValid, AItem* PlaceableItem);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivPlacementValidChanged(bool InIsValid);
    void ReceivePlacementStateChanged(ETrackBuildPlacementState NewState);
    void ReceivePlacementChangedEnd(const FTransform& NewEndTransform, UTrackBuilderConnectPoint* InConnectPoint);
    void ReceivePlacementChangedBegin(const FTransform& NewEndTransform, UTrackBuilderConnectPoint* InConnectPoint);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ReceiveCanPlaceAt(const FTransform& InCandidateTransform, UTrackBuilderConnectPoint* InConnectPoint);
    UFUNCTION()
    void OnRep_SegmentEndTransform();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrackBuilderUsable* GetTrackStartUsable() const;
    AActor* GetTrackStartActor() const;
    FTransform GetStartTransform() const;
    FTransform GetSegmentEndTransform() const;
    ETrackBuildPlacementState GetPlacementState() const;
    ATrackBuilderSegment* GetNextSegment(bool bForward) const;
    bool GetIsSegmentEndTransformValid() const;
    UTrackBuilderConnectPoint* GetConnectPoint() const;
    bool CanPlaceAt(const FTransform& InCandidateTransform, UTrackBuilderConnectPoint* InConnectPoint, AItem* PlaceableItem);
};
