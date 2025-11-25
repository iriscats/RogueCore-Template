#pragma once
#include "CoreMinimal.h"
#include "ETriggeredStatusEffectType.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "TriggeredStatusEffectUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UTriggeredStatusEffectUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    ETriggeredStatusEffectType upgradeType;
    float AoERange;
    TSubclassOf<UStatusEffect> OwnerEffect;
    UTriggeredStatusEffectUpgrade();
    UFUNCTION(BlueprintCallable)
    void OnEffectShouldTrigger(AActor* PlayerCharacter);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(AFSDPlayerState* Player, TSubclassOf<AActor> Item, TSubclassOf<UStatusEffect> NewStatusEffect, ETriggeredStatusEffectType aUpgradeType);
};
