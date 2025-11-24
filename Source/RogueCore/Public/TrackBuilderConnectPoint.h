#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SphereComponent.h"
#include "Templates/SubclassOf.h"
#include "TrackBuilderConnectPoint.generated.h"

class ATrackBuilderSegment;
class UTrackBuilderConnectPoint;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTrackBuilderConnectPoint : public USphereComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_ConnectedSegment, meta=(AllowPrivateAccess=true))

    TArray<TWeakObjectPtr<ATrackBuilderSegment>> ConnectedSegments;

    int32 MaxConnections;

    float MaxConnectRadius;

    float ConnectDistance;

    FVector MaxAngles;

    UTrackBuilderConnectPoint(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConnectionDelegate, UTrackBuilderConnectPoint*, InConnectPoint, ATrackBuilderSegment*, InSegment);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConnectionDelegate OnConnectedWithSegment;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATrackBuilderSegment> ConnectType;
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_ConnectedSegment, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ATrackBuilderSegment>> ConnectedSegments;
    int32 MaxConnections;
    float MaxConnectRadius;
    float ConnectDistance;
    FVector MaxAngles;
    UTrackBuilderConnectPoint(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_ConnectedSegment();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FTransform GetConnectTransform(const FTransform& FromWorldTransform);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ATrackBuilderSegment*> GetConnectedSegments() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Disconnect(ATrackBuilderSegment* InSegment);
    bool Connect(ATrackBuilderSegment* InSegment);
    bool CanConnectWith(ATrackBuilderSegment* InSegment, const FTransform& FromWorldTransform);
};
