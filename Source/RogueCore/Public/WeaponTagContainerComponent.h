#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "DamageListener.h"
#include "DamageRelevant.h"
#include "WeaponTagContainerComponent.generated.h"

class UWeaponRangeTag;
class UWeaponTagBase;
class UWeaponTechTag;
class UWeaponTypeTag;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponTagContainerComponent : public UActorComponent, public IDamageRelevant, public IDamageListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeaponRangeTag* RangeTag;
    
    UWeaponTypeTag* TypeTag;
    UWeaponTechTag* TechTag;
    TArray<UWeaponTagBase*> Tags;
    FGameplayTagContainer WeaponTags;
    UWeaponTagContainerComponent(const FObjectInitializer& ObjectInitializer);
    // Fix for true pure virtual functions not being implemented
};
