#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "MissionDNA.generated.h"

class UStageComplexity;
class UStageDuration;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UMissionDNA : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MissionScale;
    
    float Weight;
protected:
    int32 AmountOfStages;
    int32 XpPerStage;
    float XpPerStageNumberMultiplier;
    float ExtraStageTime;
    UStageComplexity* Complexity;
    UStageDuration* Duration;
    TArray<FGameplayTagQuery> RoomQueries;
    TArray<FGameplayTagQuery> DecorationQueries;
    TArray<int32> DecorationBudgets;
    UMissionDNA();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDurationHazardBonus() const;
    float GetComplexityHazardBonus() const;
};
