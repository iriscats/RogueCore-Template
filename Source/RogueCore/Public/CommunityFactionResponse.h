#pragma once
#include "CoreMinimal.h"
#include "CommunityFactionResponse.generated.h"

USTRUCT(BlueprintType)
struct FCommunityFactionResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Goals;
    
    TArray<float> Values;
    TArray<float> Members;
    ROGUECORE_API FCommunityFactionResponse();
};
