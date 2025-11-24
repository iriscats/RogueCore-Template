#pragma once
#include "CoreMinimal.h"
#include "HackingUsableState.generated.h"

class AHackingToolItem;
class APlayerCharacter;
USTRUCT(BlueprintType)
struct FHackingUsableState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHacked;
    
    TWeakObjectPtr<AHackingToolItem> BeingHackedByItem;
    TWeakObjectPtr<APlayerCharacter> HackedBy;
    ROGUECORE_API FHackingUsableState();
};
