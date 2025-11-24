#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Projectile.h"
#include "HydraWeedSpawnProjectile.generated.h"

UCLASS(Blueprintable, NoExport)
class AHydraWeedSpawnProjectile : public AProjectile {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FVector TargetLocation;

    

    AHydraWeedSpawnProjectile(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    AHydraWeedSpawnProjectile(const FObjectInitializer& ObjectInitializer);
};
