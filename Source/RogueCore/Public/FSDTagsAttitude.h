#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FSDTagsAttitude.generated.h"

USTRUCT(BlueprintType)
struct FFSDTagsAttitude {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Friendly;
    
    FGameplayTag Neutral;
    FGameplayTag Hostile;
    ROGUECORE_API FFSDTagsAttitude();
};
