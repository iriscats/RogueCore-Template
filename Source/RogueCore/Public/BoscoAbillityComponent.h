#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABillityChargeProgressDelegate.h"
#include "AbilityDataUpdatedDelegate.h"
#include "AbillityChargeUsedSigDelegate.h"
#include "BoscoAbilityTarget.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "BoscoAbillityComponent.generated.h"

class ABosco;
class ADroneStream;
class AProjectileBase;
class UBoscoProjectileAbillity;
class UItemUpgrade;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBoscoAbillityComponent : public UActorComponent, public IUpgradable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FABillityChargeProgress OnAbillityChargeProgress;
    
    FAbillityChargeUsedSig OnAbillityChargeUsed;
    FAbilityDataUpdated OnAbilityDataUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBoscoAbilityTarget Target;
    TArray<UItemUpgrade*> upgrades;
    TSubclassOf<AProjectileBase> ProjectileClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADroneStream> StreamClass;
    TWeakObjectPtr<ABosco> AbillityOwner;
    TArray<UItemUpgrade*> ProjectileUpgrades;
    UBoscoProjectileAbillity* AbilityData;
    bool InitializeAtBeginPlay;
    UBoscoAbillityComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxCharges(bool Total) const;
    bool GetIsSet() const;
    int32 GetCharges() const;
    // Fix for true pure virtual functions not being implemented
};
