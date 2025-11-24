#pragma once
#include "CoreMinimal.h"
#include "AttackerInfo.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FAttackerInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Attacker;
    
    int32 PositionIndex;
    float AttackerRadius;
    ROGUECORE_API FAttackerInfo();
};
