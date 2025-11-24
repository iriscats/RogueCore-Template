#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "AmmoDrivenWeapon.h"
#include "DamageInstance.h"
#include "ShockBlaster.generated.h"

class AActor;
class AFSDPawn;
class UHitscanComponent;
class UNiagaraSystem;
class UPhysicalMaterial;
class USoundCue;
UCLASS(Blueprintable, NoExport)
class AShockBlaster : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ImpactEffect;
    UNiagaraSystem* BeamEffect;
    USoundCue* ImpactSound;
    FDamageInstance BaseDamage;
    FName BeamStartPositionParam;
    FName BeamTargetPositionParam;
    FName BeamDistanceParam;
    float BounceDelay;
    float RicochetRange;
    float AmmoCostPerBounce;
    int32 AttitudeQuery;
    AShockBlaster(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnRicochetEffects(const TArray<AFSDPawn*>& InPawnsHit);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(AActor* Hit, float Damage, UPhysicalMaterial* PhysMaterial, int32 clipAmount);
    UFUNCTION(Reliable, Server)
    void Server_OnHitScan_Hit(const FHitResult& InHitResult, const float InDamage, const uint32 InRicochetCount);
    UFUNCTION(BlueprintCallable)
    void OnHitScan_Hit(const FHitResult& InHitResult, const bool InAlwaysPenetrate);
    void DoBounce();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(AActor* Hit);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_OnHitScan_Hit(FVector_NetQuantize InHitLocation);
};
