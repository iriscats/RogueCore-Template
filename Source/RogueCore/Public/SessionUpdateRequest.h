#pragma once
#include "CoreMinimal.h"
#include "SessionUpdateRequest.generated.h"

USTRUCT(BlueprintType)
struct FSessionUpdateRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SessionKey;
    
    int32 NumPlayers;
    ROGUECORE_API FSessionUpdateRequest();
};
