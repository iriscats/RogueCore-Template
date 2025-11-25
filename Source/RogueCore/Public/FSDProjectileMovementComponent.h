#pragma once
#include "CoreMinimal.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Templates/SubclassOf.h"
#include "FSDProjectileMovementComponent.generated.h"

class AActor;
class UCurveFloat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFSDProjectileMovementComponent : public UProjectileMovementComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectilePenetrateDelegate, const FHitResult&, ImpactResult);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileOutOfPropulsion);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProjectilePenetrateDelegate OnProjectilePenetrate;
    FOnProjectileOutOfPropulsion OnProjectileOutOfPropulsion;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShouldPenetrate: 1;
    bool HomingToCenter;
 
    TArray<TSubclassOf<AActor>> IgnoreCollisionAgainst;
    bool InvertIgnoreCollisionAgainst;
    UCurveFloat* AccelerationCurve;
    float AccelerationMultiplier;
    float MaxPropulsionTime;
    float GravityScale;
    uint8 bCancelPenetration: 1;
    UFSDProjectileMovementComponent(const FObjectInitializer& ObjectInitializer);
};
