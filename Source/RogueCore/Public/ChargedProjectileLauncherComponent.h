#pragma once
#include "CoreMinimal.h"
#include "ProjectileLauncherBaseComponent.h"
#include "Templates/SubclassOf.h"
#include "ChargedProjectileLauncherComponent.generated.h"

class AProjectileBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UChargedProjectileLauncherComponent : public UProjectileLauncherBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> NormalProjectileClass;
    
    TSubclassOf<AProjectileBase> ChargedProjectileClass;
    float ProjectileChangeChargeValue;
    UChargedProjectileLauncherComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetProjectileClassCharged(TSubclassOf<AProjectileBase> NewProjectileClass);
    void SetProjectileClass(TSubclassOf<AProjectileBase> NewProjectileClass);
};
