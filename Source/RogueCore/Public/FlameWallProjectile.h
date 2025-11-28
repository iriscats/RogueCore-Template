#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "Templates/SubclassOf.h"
#include "FlameWallProjectile.generated.h"

class AActor;
class AFlameWallSegment;
UCLASS(Abstract, Blueprintable)
class AFlameWallProjectile : public AProjectile {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlameWallSegment> SegmentParticleClass;
 
    
    int32 SegmentCount;
    float WallWidth;
    TSubclassOf<AActor> ImpactClass;
    AFlameWallProjectile(const FObjectInitializer& ObjectInitializer);
};
