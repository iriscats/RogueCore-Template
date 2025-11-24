#pragma once
#include "CoreMinimal.h"
#include "DelayedActorSwitchData.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FDelayedActorSwitchData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Actor;
    
    uint8 IsActive: 1;
    uint8 IsExternalActor: 1;
    uint8 IsUnEquipCalled: 1;
    ROGUECORE_API FDelayedActorSwitchData();
};
