#pragma once
#include "CoreMinimal.h"
#include "MultiHitscanWeapon.h"
#include "Templates/SubclassOf.h"
#include "AutoShotgun.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPrimitiveComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AAutoShotgun : public AMultiHitscanWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> CQCKillBuff;
    
    AAutoShotgun(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysicalMaterial, bool wasDirectHit);
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
};
