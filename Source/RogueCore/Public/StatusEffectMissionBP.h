#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StageLogic.h"
#include "Templates/SubclassOf.h"
#include "StatusEffectMissionBP.generated.h"

class APawn;
class UEnemyDescriptor;
class UStatusEffect;
UCLASS(Blueprintable)
class UStatusEffectMissionBP : public UStageLogic {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FGameplayTagQuery EnemyQuery;

    

    TSubclassOf<UStatusEffect> StatusEffect;

    UStatusEffectMissionBP();

    UFUNCTION(BlueprintCallable)

    void OnEnemySpawned(APawn* Pawn, UEnemyDescriptor* descriptor);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery EnemyQuery;
    
    TSubclassOf<UStatusEffect> StatusEffect;
    UStatusEffectMissionBP();
    UFUNCTION(BlueprintCallable)
    void OnEnemySpawned(APawn* Pawn, UEnemyDescriptor* descriptor);
};
