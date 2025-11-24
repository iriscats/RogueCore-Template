#pragma once
#include "CoreMinimal.h"
#include "CreditsReward.generated.h"

USTRUCT(BlueprintType)
struct FCreditsReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    int32 amount;
    ROGUECORE_API FCreditsReward();
};
