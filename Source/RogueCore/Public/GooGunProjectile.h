#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Projectile.h"
#include "Templates/SubclassOf.h"
#include "GooGunProjectile.generated.h"

class AActor;
class AGooGunPuddle;
class UPrimitiveComponent;
UCLASS(Blueprintable, NoExport)
class AGooGunProjectile : public AProjectile {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PuddleLifeTime;
    
    int32 FragmentCount;
    AGooGunProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    AGooGunPuddle* SpawnPuddle(FTransform Transform, TSubclassOf<AGooGunPuddle> PuddleClass);
    void DealSocketArmorDamage(AActor* Actor, UPrimitiveComponent* Target);
};
