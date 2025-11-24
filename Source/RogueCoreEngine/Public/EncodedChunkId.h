#pragma once
#include "CoreMinimal.h"
#include "EncodedChunkId.generated.h"

USTRUCT(BlueprintType)
struct FEncodedChunkId {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ID;
    
    ROGUECOREENGINE_API FEncodedChunkId();
};

