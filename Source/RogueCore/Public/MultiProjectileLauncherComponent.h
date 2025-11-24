#pragma once
#include "CoreMinimal.h"
#include "MultiProjectileSpawnData.h"
#include "ProjectileLauncherComponent.h"
#include "MultiProjectileLauncherComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMultiProjectileLauncherComponent : public UProjectileLauncherComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProjectilesPerShot;
    
    TArray<FMultiProjectileSpawnData> ProjectileData;
    UMultiProjectileLauncherComponent(const FObjectInitializer& ObjectInitializer);
};
