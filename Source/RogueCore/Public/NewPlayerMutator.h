#pragma once
#include "CoreMinimal.h"
#include "NewPlayerMutator.generated.h"

class UMutator;
USTRUCT(BlueprintType)
struct FNewPlayerMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinCampaignProgress;
    
    int32 MaxCampaignProgress;
    TArray<UMutator*> Mutators;
    ROGUECORE_API FNewPlayerMutator();
};
