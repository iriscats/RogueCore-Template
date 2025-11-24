#pragma once
#include "CoreMinimal.h"
#include "PlayerInfrontState.generated.h"

class APlayerCharacter;
USTRUCT(BlueprintType)
struct FPlayerInfrontState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Player;
    
    bool inFront;
    ROGUECORE_API FPlayerInfrontState();
};
