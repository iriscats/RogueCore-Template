#pragma once
#include "CoreMinimal.h"
#include "PerkEffect.h"
#include "PerkEffectEscapeGrabber.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class UPerkEffectEscapeGrabber : public UPerkEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> EnemyGrabberClass;
    
    UPerkEffectEscapeGrabber();
};
