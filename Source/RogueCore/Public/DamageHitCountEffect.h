#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WeaponHitCountEffect.h"
#include "DamageHitCountEffect.generated.h"

class UDamageClass;
class UFXSystemAsset;
class USoundCue;
class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UDamageHitCountEffect : public UWeaponHitCountEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamagePerHit;
    
    UDamageClass* DamageClass;
    UFXSystemAsset* DamageParticle;
    USoundCue* DamageSound;
    bool DeadBugWalkingTargetMarking;
    float ExtraDamageForCalculatingDBW;
    TSubclassOf<UStatusEffect> DeadBugWalkingSTE;
    UDamageHitCountEffect();
};
