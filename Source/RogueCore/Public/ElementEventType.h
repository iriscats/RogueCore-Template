#pragma once
#include "CoreMinimal.h"
#include "ElementEventSetup.h"
#include "SavableDataAsset.h"
#include "ElementEventType.generated.h"

class UNiagaraSystem;
class USoundCue;
UCLASS(Blueprintable)
class UElementEventType : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnActivateSoundCue;
    
    USoundCue* OnDeactivateSoundCue;
    UNiagaraSystem* OnActivateParticleSystem;
    UNiagaraSystem* OnDeactivateParticleSystem;
protected:
    float DamageBonus;
    FElementEventSetup EventSetup;
    bool PlayerOverrideSetup;
    FElementEventSetup EventSetupPlayerOverride;
    UElementEventType();
};
