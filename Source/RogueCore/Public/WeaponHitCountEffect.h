#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponHitCountEffect.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UWeaponHitCountEffect : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UsesDamageEffects;
    
    UWeaponHitCountEffect();
};
