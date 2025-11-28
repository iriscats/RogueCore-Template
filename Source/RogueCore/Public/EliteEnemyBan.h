#pragma once
#include "CoreMinimal.h"

#include "EliteEnemyBan.generated.h"

class UStageTemplate;
USTRUCT(BlueprintType)
struct FEliteEnemyBan {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval AffectedPlayerCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageTemplate* Template;
    ROGUECORE_API FEliteEnemyBan();
};
