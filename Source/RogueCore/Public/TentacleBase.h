#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyPawn.h"
#include "TentacleBase.generated.h"

class AStabberVineRoot;
class USceneComponent;
class USplineComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ATentacleBase : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RestTransform;
    FVector TargetLocation;
    float HeadMovementDuration;
    float CanSwayCooldown;
    FVector2D SwayRange;
    float NeckBaseTangentLength;
    FVector NeckBasePositionOffset;
    FVector NeckBaseTangentOffset;
    float NeckTopTangentLength;
    float DurationTentacleRetract;
    float DurationTentacleFoldout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* HeadRoot;
    USceneComponent* HeadRotator;
    ATentacleBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetRestingTransform(const FTransform& restingTransform, bool startAtRest);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Recieve_OnRep_Owner();
    void MoveHydraHead(FTransform newDesiredTransform, float newCanSwayCooldown, float newHeadMovementDuration, bool UseSpring);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AStabberVineRoot* GetStabberVineRoot() const;
    USceneComponent* GetHeadRotator();
    USceneComponent* GetHeadRoot();
};
