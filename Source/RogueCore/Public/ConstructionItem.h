#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ConstructionItem.generated.h"

class AStructureActor;
USTRUCT(BlueprintType)
struct FConstructionItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AStructureActor> StructureClass;
    
    int32 SpawnBudgetCost;
    FGameplayTagContainer Tags;
    float SpawnWeight;
    ROGUECORE_API FConstructionItem();
};
