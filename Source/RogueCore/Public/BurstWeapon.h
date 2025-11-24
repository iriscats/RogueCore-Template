#pragma once
#include "CoreMinimal.h"
#include "HitscanWeapon.h"
#include "BurstWeapon.generated.h"

class UDamageAsset;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPrimitiveComponent;
UCLASS(Blueprintable, NoExport)
class ABurstWeapon : public AHitscanWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* BurstBonusDamage;

    ABurstWeapon(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReadyToFire();
};
