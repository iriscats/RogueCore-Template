#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageParams.generated.h"

class AActor;
class APawn;
class UBaseArmorDamageComponent;
class UDamageImpulse;
class UDamageListenerCollection;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPawnStatsComponent;
class UPrimitiveComponent;
class UUpgradeContainerComponent;
class UWeaponTagContainerComponent;
USTRUCT(BlueprintType)
struct FDamageParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    TArray<AActor*> IgnoreActors;
    AActor* Target;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* HitComponent;
    UHealthComponentBase* TargetHealth;
    UBaseArmorDamageComponent* TargetArmorDamage;
    UPawnStatsComponent* TargetStats;
    AActor* DamageCauser;
    UWeaponTagContainerComponent* CauserWeaponTags;
    UUpgradeContainerComponent* CauserUpgradeContainer;
    UUpgradeContainerComponent* InstigatorUpgradeContainer;
    UDamageListenerCollection* CauserListenerCollection;
    UDamageListenerCollection* InstigatorListenerCollection;
    UDamageListenerCollection* TargetListenerCollection;
    APawn* Instigator;
    UPawnStatsComponent* InstigatorStats;
    UPawnStatsComponent* MinionOwnerPawnStat;
    UFSDPhysicalMaterial* PhysicalMaterial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDamageImpulse* Impulse;
    float PrefetchedCritRoll;
    float PrefetchedCritChance;
    int32 OverriddenCritLevel;
    int32 ClipCount;
    int32 BoneIndex;
    bool CollectBonuses;
    ROGUECORE_API FDamageParams();
};
