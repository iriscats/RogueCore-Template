#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "BXELogicUnlockComponent.h"
#include "DamageInstance.h"
#include "ExplosiveShotsComponent.generated.h"

class UNiagaraSystem;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExplosiveShotsComponent : public UBXELogicUnlockComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageInstance instance;
    
    USoundCue* Sound;
    UNiagaraSystem* Effect;
    UExplosiveShotsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowEffects(const FVector_NetQuantize& Location);
};
