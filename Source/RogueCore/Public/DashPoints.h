#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/NetSerialization.h"
#include "DashSigDelegate.h"
#include "EDashPointsGenerationMode.h"
#include "DashPoints.generated.h"

class AActor;
class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDashPoints : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDashSig OnStartDashEvent;
    
    FDashSig OnStopDashEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize DashLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve DashSpeedCurve;
    float PointOffset;
    float MaxRangeFromPlayer;
    float MinRangeFromPlayer;
    float MinHeightAboveTarget;
    float MaxHeightAboveTarget;
    float safeReduction;
    float AcceptedDashradius;
    float DashSpeed;
    float SlowdownRadius;
    int32 IgnoreTheClosestPoints;
    EDashPointsGenerationMode GenerationMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Dashing, meta=(AllowPrivateAccess=true))
    bool IsDashing;
    bool IgnoreRules;
    UDashPoints(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateDashPointData();
    void StopDashing();
    void StartDashing();
    UFUNCTION()
    void OnRep_Dashing();
    void OnParentDeath(UHealthComponentBase* Health);
    FVector GetDashPoint(AActor* fromTarget, bool& success);
};
