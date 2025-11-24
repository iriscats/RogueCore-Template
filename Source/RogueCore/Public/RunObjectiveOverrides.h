#pragma once
#include "CoreMinimal.h"
#include "ERunItemOverrideType.h"
#include "ERunListOverrideType.h"
#include "Templates/SubclassOf.h"
#include "RunObjectiveOverrides.generated.h"

class UObjective;
USTRUCT(BlueprintType)
struct FRunObjectiveOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERunItemOverrideType PrimaryObjectiveOverride;
    
    TSubclassOf<UObjective> PrimaryObjective;
    ERunListOverrideType SecondaryObjectivesOverride;
    TArray<TSubclassOf<UObjective>> SecondaryObjectives;
    ERunListOverrideType ExpeniteObjectivesOverride;
    TArray<TSubclassOf<UObjective>> ExpeniteObjectives;
    ROGUECORE_API FRunObjectiveOverrides();
};
