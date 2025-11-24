#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SpawnActor.generated.h"

class AAbilitySpawnActor;
USTRUCT(BlueprintType)
struct FSpawnActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAbilitySpawnActor> SpawnActor;
    
    ROGUECORE_API FSpawnActor();
};
