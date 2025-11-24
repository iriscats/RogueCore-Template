#pragma once
#include "CoreMinimal.h"
#include "GVisibilityGroups.generated.h"

class UHUDVisibilityGroup;
USTRUCT(BlueprintType)
struct FGVisibilityGroups {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UHUDVisibilityGroup*> AllGroups;
    
    UHUDVisibilityGroup* EnemyHealth;
    ROGUECORE_API FGVisibilityGroups();
};
