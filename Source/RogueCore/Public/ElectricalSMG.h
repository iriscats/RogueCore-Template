#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "HitscanWeapon.h"
#include "Templates/SubclassOf.h"
#include "ElectricalSMG.generated.h"

class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UHealthComponentBase;
class UPrimitiveComponent;
class USoundCue;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AElectricalSMG : public AHitscanWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> AoEStatusEffect;
    
    UFXSystemAsset* AoEParticle;
    USoundCue* AoESound;
    float AoEStatusEffectChance;
    float AoEStatusEffectRange;
    AElectricalSMG(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    void OnStatusEffectPushed(UHealthComponentBase* Health);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_OnAoETriggered(const FVector_NetQuantize& Location, const FVector_NetQuantizeNormal& Normal) const;
};
