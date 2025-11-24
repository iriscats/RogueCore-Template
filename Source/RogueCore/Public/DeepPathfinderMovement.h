#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UnrealType.h"
#include "Engine/LatentActionManager.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Engine/NetSerialization.h"
#include "DeepPathFinderPreference.h"
#include "DeepPathFinderSize.h"
#include "DeepPathFinderType.h"
#include "AsyncPathRequestsInterface.h"
#include "DeepRepPath.h"
#include "EDeepMovementMode.h"
#include "EDeepMovementState.h"
#include "EOffsetFrom.h"
#include "FakeMoverState.h"
#include "HandleRotationOptions.h"
#include "PathBeginDelegate.h"
#include "PathFinishedDelegate.h"
#include "PathStateChangedDelegateDelegate.h"
#include "PauseMovementElapsedDelegate.h"
#include "RefreshDestinationDelegate.h"
#include "DeepPathfinderMovement.generated.h"

class AActor;
class ADeepCSGWorld;
class UFakeMoverSettings;
class UPawnStatsComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDeepPathfinderMovement : public UPawnMovementComponent, public IAsyncPathRequestsInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseDormancy;
    
    float MaxPawnSpeed;
    float StrafeSpeed;
    float MinSlowdownAngle;
    float MaxSlowdownAngle;
    float MaxStrafeDistance;
    float AlignDirectionSpeed;
    float FleeSpeedBoostMultiplier;
    float MaxAcceleration;
    float MaxBrakingDeceleration;
    float AngleSpeedFilterFactor;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 AIAvoidanceWeight;
    DeepPathFinderType PathfinderType;
    DeepPathFinderSize PathfinderSize;
    ETeleportType MovementPhysicsType;
    DeepPathFinderPreference PathfinderPreference;
    bool AlignTowardsTargetIfStationary;
    float AlignToTargetMinRequiredAngle;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FVector_NetQuantizeNormal AlignTowardsDirection;
    bool AllowSlowTickRateWhenNotVisible;
    bool ForceAPathIfNoneFound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DrawServerPath;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathBegin OnPathBegin;
    FPauseMovementElapsed OnPauseMovementElapsed;
    FPathFinished OnPathFinished;
    FRefreshDestination OnRefreshDestination;
    FPathStateChangedDelegate OnStateChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool IsStrafingOverride;
private:
    ADeepCSGWorld* CSGWorld;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Path, meta=(AllowPrivateAccess=true))
    FDeepRepPath Path;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MoveSettings, meta=(AllowPrivateAccess=true))
    UFakeMoverSettings* MoveSettings;
    AActor* targetActor;
    int32 CurrentPathIndex;
    float CurrentPathFraction;
    FVector Destination;
    AActor* DestinationActor;
    float AcceptanceRadius;
    bool OnlyPartPath;
    float PauseMovementTime;
    EDeepMovementMode MoveMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPawnStatsComponent* PawnStats;
    FVector LastForwardDir;
    float VerticalAngleSpeed;
    float HorizontalAngleSpeed;
    float VerticalAngleSpeedRaw;
    float HorizontalAngleSpeedRaw;
    bool IsStrafing;
    bool HasOustandingPathRequest;
    bool LastPathReachedPreciseDestination;
    float PostponedTickTime;
    bool LastMoveSuccessful;
    bool HandleRotation;
    bool TickAfterOwnerDeath;
    FHandleRotationOptions HandleRotationOptions;
    FVector UnfilteredPosition;
    FVector LastDestPosUsed;
    float DampOmega;
    bool UseMovementSpring;
    bool SnapToPathfinderOnFirstMove;
    FFakeMoverState FakePhysicsMove;
    float FakeSyncTime;
    UDeepPathfinderMovement(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateTargetActor(AActor* NewTarget);
    void UpdateDestination(const FVector& Dest);
    void UnPauseMovement();
    void TeleportTo(const FVector& destLoc, const FRotator& destRot);
    void StopMove();
    void StopAttackStance();
    bool StartMoveToActor(AActor* Dest, float NewAcceptanceRadius, bool ToCenterOfMass);
    bool StartMoveTo(const FVector& Dest, float NewAcceptanceRadius);
    bool StartFleeFrom(const FVector& dangerPos, float Distance);
    void StartFakePhysicsMoveSet(UFakeMoverSettings* NewMoveSettings);
    void StartFakePhysics(const FVector& Vel);
    void StartAttackStance(const FVector& stancePos);
    void SnapToPathfinder();
    void SetSlowDownAngles(const float min, const float max);
    void SetMaxSpeed(const float Speed);
    void SetMaxAcceleration(float Value);
    void SetHandleRotation(const bool Flag);
    void SetFreezeAlignment(bool Freeze);
    void SetControlledExternally(bool controlled);
    void PushMovementPause();
    void PopMovementPause();
    void PauseMovement(float Time);
    bool PathExistTo(const FVector& Dest);
    bool PathExistsBetween(const FVector& From, const FVector& To);
    UFUNCTION()
    void OnRep_Path(const FDeepRepPath& oldPath);
    UFUNCTION()
    void OnRep_MoveSettings(const UFakeMoverSettings* NewMoveSettings);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFreezeAlignmentSet() const;
    float GetVerticalAngleSpeedRaw();
    float GetVerticalAngleSpeed();
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    void GetRandomSpawnPointAtApproximateDistance_Async(const FVector& Origin, float Distance, bool& success, FVector& outPos, FLatentActionInfo LatentInfo);
    void GetRandomReachablePointAtApproximateDistance_Async(const FVector& Origin, float Distance, bool& success, FVector& outPos, FLatentActionInfo LatentInfo);
    bool GetRandomReachablePointAtApproximateDistance(const FVector& Origin, float Distance, FVector& outPos);
    FVector GetPathForwardDirection();
    DeepPathFinderType GetPathfinderType() const;
    DeepPathFinderSize GetPathfinderSize() const;
    EDeepMovementState GetMovementState() const;
    float GetMaxPawnSpeed() const;
    float GetMaxAcceleration() const;
    bool GetIsStrafing();
    float GetHorizontalAngleSpeedRaw();
    float GetHorizontalAngleSpeed();
    FVector GetCurrentMovePos() const;
    UFakeMoverSettings* GetCurrentFakePhysicsMoveSet();
    float GetApproximatePathLength(FVector Start, FVector End) const;
    bool FlyToConnectedPosition(const FVector& destPos);
    bool FindPointKeepingDistance(const FVector& Origin, float MinDistance, float MaxDistance, const FVector& Target, float idealTargetDistance, FVector& outPos);
    bool FindPointDiagonalTowardsTarget(const FVector& Origin, const FVector& Target, float dodgeAngle, float maxSampleDistance, float moveDistance, float RandomDeviation, FVector& outPos);
    FVector FindPathfinderPointBelow(const FVector& Pos, float HeightOffset);
    FVector FindPathfinderPointAbove(const FVector& Pos, float HeightOffset);
    FVector FindPathfinderOffsetPoint(const FVector& Pos, const EOffsetFrom offsetFrom, float HeightOffset);
    bool FindOrthogonalPointFromTarget(const FVector& Origin, const FVector& Target, float maxSampleDistance, float idealTargetDistance, FVector& outPos);
    FVector FindNearestPathfinderPointOverrideType(const FVector& Pos, DeepPathFinderType OverrideType, float MaxDistance);
    void FindNearestPathfinderPoint_Async(const FVector& Pos, float MaxDistance, bool& success, FVector& outPos, FLatentActionInfo LatentInfo);
    FVector FindNearestPathfinderPoint(const FVector& Pos, float MaxDistance) const;
    FVector FindNearestConnectedPathfinderPoint(const FVector& Pos, float MaxDistance);
    FQuat CalcPathfinderOrientation(const FVector& Pos, const FVector& forwardDir);
    bool BackOffFrom(const FVector& dangerPos, float Distance);
    void AddFakeMoverImpulse(const FVector& Impulse);
    // Fix for true pure virtual functions not being implemented
};
