#pragma once
#include "CoreMinimal.h"
#include "TerminatorShoutState.generated.h"

class USoundCue;
USTRUCT(BlueprintType)
struct FTerminatorShoutState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    TArray<USoundCue*> Shouts;
    bool Loop;
    float MaxRandomShoutDelay;
    float MinRandomShoutDelay;
    bool Interruptable;
    bool PreventSubsequentDuplicate;
    ROGUECORE_API FTerminatorShoutState();
};
