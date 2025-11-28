#pragma once
#include "CoreMinimal.h"
#include "DelegateDelegate.h"
#include "EImpactDecalSize.h"
#include "ERicochetBehavior.h"
#include "WeaponFireComponent.h"
#include "HitscanBaseComponent.generated.h"

class AActor;
class UDamageAsset;
class UDamageComponent;
class UElementType;
class UPawnStatsComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHitscanBaseComponent : public UWeaponFireComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnFireComplete;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    UDamageAsset* Damage;
    bool UseDamageComponent;
    int32 MaxPenetrations;
    EImpactDecalSize ImpactDecalSize;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoredActorsInTrace;
    ERicochetBehavior RicochetBehavior;
    float RicochetChance;
    bool RicochetOnWeakspotOnly;
    float RicochetMaxRange;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPawnStatsComponent> ParentPawnStats;
    TArray<UElementType*> ActiveElementTypes;
    UHitscanBaseComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StopFire();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RemoveDebris(int32 instance, int32 Component);
};
