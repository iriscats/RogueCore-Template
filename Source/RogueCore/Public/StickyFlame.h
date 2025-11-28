#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "DecalData.h"
#include "StickyFlame.generated.h"

class UAudioComponent;
class UNiagaraComponent;
class UStatusEffectTriggerComponent;
UCLASS(Blueprintable)
class AStickyFlame : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* FlameParticlesNS;
    
    UAudioComponent* Audio;
    UStatusEffectTriggerComponent* StatusTriggerComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalData Decal;
    float FlameLifetime;
    float FlameExtinguishTime;
    FVector2D RandomTimeRangeFactor;
    float AudioFadeOutTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsActive, meta=(AllowPrivateAccess=true))
    bool IsActive;
    AStickyFlame(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_IsActive();
    void OnExtinguisFlame();
};
