#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "CrossbowProjectileRicochet.generated.h"

class ACrossbowProjectileBase;
class UNiagaraSystem;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrossbowProjectileRicochet : public UActorComponent {
    GENERATED_BODY()
    

public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraTrailParticleSystem;
    
    int32 RicochetMax;
    float RicochetRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACrossbowProjectileBase* CastedOwner;
    UCrossbowProjectileRicochet(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable)
    void Ricochet(const FHitResult& HitResult, const FVector& RelativeLocation);
};
