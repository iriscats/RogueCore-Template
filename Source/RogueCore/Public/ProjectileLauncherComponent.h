#pragma once
#include "CoreMinimal.h"
#include "ProjectileLauncherBaseComponent.h"
#include "Templates/SubclassOf.h"
#include "ProjectileLauncherComponent.generated.h"

class AProjectileBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileLauncherComponent : public UProjectileLauncherBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> ProjectileClass;
    
    UProjectileLauncherComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetProjectileClass(TSubclassOf<AProjectileBase> NewProjectileClass);
};
