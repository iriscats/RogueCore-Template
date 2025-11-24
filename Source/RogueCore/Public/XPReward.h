#pragma once
#include "CoreMinimal.h"
#include "XPReward.generated.h"

USTRUCT(BlueprintType)
struct FXPReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    int32 XP;
    ROGUECORE_API FXPReward();
};
