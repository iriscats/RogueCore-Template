#pragma once
#include "CoreMinimal.h"
#include "LookupSessionResponse.generated.h"

USTRUCT(BlueprintType)
struct FLookupSessionResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Valid;
    
    FString LobbyId;
    FString P2PADDR;
    int32 P2PPORT;
    ROGUECORE_API FLookupSessionResponse();
};
