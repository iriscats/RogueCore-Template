#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "MultiProjectileSpawnData.generated.h"

class AProjectile;
USTRUCT(BlueprintType)
struct FMultiProjectileSpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> ProjectileClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HorizontalAngleOffset;
    FFloatInterval VerticalAngleOffset;
    FFloatInterval Delay;
    bool IsBallistic;
    float HorizontalOriginOffset;
    float VerticalOriginOffset;
    ROGUECORE_API FMultiProjectileSpawnData();
};
