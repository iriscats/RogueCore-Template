#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "BumpPlayerHit.generated.h"

class APlayerCharacter;
USTRUCT(BlueprintType)
struct FBumpPlayerHit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Force;
    
    APlayerCharacter* Player;
    ROGUECORE_API FBumpPlayerHit();
};
