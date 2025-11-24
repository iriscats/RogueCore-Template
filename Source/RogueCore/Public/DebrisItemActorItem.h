#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DebrisItemActorItem.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FDebrisItemActorItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Actor;
    
    float Probability;
    ROGUECORE_API FDebrisItemActorItem();
};
