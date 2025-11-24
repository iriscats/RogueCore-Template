#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockTier.generated.h"

class UBXEUnlockAction;
USTRUCT(BlueprintType)
struct FBXEUnlockTier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockAction*> Actions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModifierNumber;
    ROGUECORE_API FBXEUnlockTier();
};
