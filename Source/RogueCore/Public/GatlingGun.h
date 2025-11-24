#pragma once
#include "CoreMinimal.h"
#include "BeltDrivenWeapon.h"
#include "GatlingGun.generated.h"

class AActor;
class UDamageAsset;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UHitscanComponent;
UCLASS(Blueprintable, NoExport)
class AGatlingGun : public ABeltDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UHitscanComponent* HitscanComponent;

    AGatlingGun(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BarrelProximityDamageEnabled;
    
    float BarrelProximityDamageDistance;
    float BarrelProximityDamageRadius;
    float BarrelProximityDamageLength;
    float TimeBetweenProximityDamageTicks;
    float DamageMultiplierAtMaxStabilization;
    UFXSystemAsset* HotShellsTracerParticles;
    float HeatRemovedOnKill;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CriticalOverheatEnabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HotShellsTracerOn, meta=(AllowPrivateAccess=true))
    bool HotShellsOn;
    float HotShellsTemperatureRequired;
    UDamageAsset* BarrelProximityDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    AGatlingGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetHotShellsOn(bool hotShellsIsOn);
    UFUNCTION(BlueprintCallable)
    void OnRep_HotShellsTracerOn();
    void OnGatlingTemperatureChanged(float temperature, bool IsOverheated);
    void OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_RemoveHeat();
};
