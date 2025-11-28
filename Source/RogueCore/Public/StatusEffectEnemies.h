#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StageLogic.h"
#include "Templates/SubclassOf.h"
#include "StatusEffectEnemies.generated.h"

class APawn;
class UEnemyDescriptor;
class UStatusEffect;
UCLASS(Abstract, Blueprintable)
class UStatusEffectEnemies : public UStageLogic {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffects;
    
    FGameplayTagContainer AllowedFilter;
    FGameplayTagQuery AllowedQuery;
    float ChanceToApply;
    bool OverrideReplacesDefault;
    TMap<UEnemyDescriptor*, TSubclassOf<UStatusEffect>> Overrides;
    UStatusEffectEnemies();
    UFUNCTION(BlueprintCallable)
    void OnEnemySpawned(APawn* Enemy, UEnemyDescriptor* descriptor);
};
