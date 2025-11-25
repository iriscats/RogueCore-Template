#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StageLogic.h"
#include "ExterminationReward.generated.h"

class AActor;
class UResourceData;
UCLASS(Abstract, Blueprintable)
class UExterminationReward : public UStageLogic {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    float AwardSize;
    FGameplayTagContainer AllowedFilter;
    UExterminationReward();
    UFUNCTION(BlueprintCallable)
    void OnEnemyKilled(const FGameplayTagContainer& GameplayTags, AActor* killedEnemy);
};
