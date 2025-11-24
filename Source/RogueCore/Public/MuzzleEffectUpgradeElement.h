#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "MuzzleEffectUpgradeElement.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable, EditInlineNew)
class UMuzzleEffectUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> FPMuzzleFlash;
    
    TSoftObjectPtr<UNiagaraSystem> TPMuzzleFlash;
    UMuzzleEffectUpgradeElement();
};
