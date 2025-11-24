#pragma once
#include "CoreMinimal.h"
#include "EquippedActorData.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FEquippedActorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    uint8 IsExternalActor: 1;
    ROGUECORE_API FEquippedActorData();
};
