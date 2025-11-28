#pragma once
#include "CoreMinimal.h"
#include "MissionTemplateItem.generated.h"

class UStageTemplate;
USTRUCT(BlueprintType)
struct FMissionTemplateItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageTemplate* Template;
    
    float Rarity;
    ROGUECORE_API FMissionTemplateItem();
};
