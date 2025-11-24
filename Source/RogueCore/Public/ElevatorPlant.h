#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "COnStateChangedDelegate.h"
#include "StartTimelineEventDelegate.h"
#include "ElevatorPlant.generated.h"

class UAudioComponent;
class UCurveFloat;
class USceneComponent;
class USoundCue;
class USplineMeshComponent;
UCLASS(Blueprintable, NoExport)
class AElevatorPlant : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Open, meta=(AllowPrivateAccess=true))

    bool IsOpen;

    bool Extend;

    UCurveFloat* DipOffsetCurve;

    UCurveFloat* LocationLerpCurve;

    AElevatorPlant(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartTimelineEvent OnStartTimelineEvent;
    
    FCOnStateChanged COnStateChangedEvent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* MovingSoundComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* GrabSound;
    FVector RestPositionOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector RelativeRestLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RelavtiveDestinationLocation, meta=(AllowPrivateAccess=true))
    FVector RelativeDestinationLocation;
    FVector BaseTangentDirectionOffset;
    FVector LeafTangentDirectionOffset;
    FVector LeafLocationNoise;
    FRotator LeafNoiseRotator;
    float BaseTangentLength;
    USplineMeshComponent* CSplineMesh;
    USceneComponent* CVineBase;
    USceneComponent* CVineLeaf;
    float InitialBaseTangentLength;
    float LeafLocationNoiseSize;
    float VineMovementAlpha;
    bool IsMoving;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Open, meta=(AllowPrivateAccess=true))
    bool IsOpen;
    bool Extend;
    UCurveFloat* DipOffsetCurve;
    UCurveFloat* LocationLerpCurve;
    AElevatorPlant(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetLeafNoiseRotator(const FRotator& aRotator);
    void SetLeafLocationNoise(const FVector& aVector);
    void SetIsOpen(bool aValue);
    void SetIsExtended(bool aValue);
    void SetBaseTangentLength(float Value);
    void SetBaseTangentDirectionOffset(const FVector& aVector);
    UFUNCTION()
    void OnRep_RelavtiveDestinationLocation();
    UFUNCTION()
    void OnRep_Open();
    void OnMatchStarted();
    void MoreTick(const FVector& DipOffset, float aValue);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVineMovementAlpha() const;
    FVector GetRelativeRestLocation() const;
    FVector GetRelativeDestinationLocation() const;
    float GetLeafLocationNoiseSize() const;
    bool GetIsMoving() const;
    bool GetIsExtended() const;
    float GetInitialTangentLenth() const;
};
