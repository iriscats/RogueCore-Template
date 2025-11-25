#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ETagBonus.h"
#include "TagBonusChangedDelegateDelegate.h"
#include "TagBonuses.h"
#include "WeaponTagBonusesComponent.generated.h"

class UWeaponTagBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponTagBonusesComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTagBonusChangedDelegate OnTagBonusChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Bonuses, meta=(AllowPrivateAccess=true))
    TArray<FTagBonuses> Bonuses;
    UWeaponTagBonusesComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_Bonuses();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBonuses(ETagBonus Bonus, const TArray<UWeaponTagBase*>& Tags) const;
};
