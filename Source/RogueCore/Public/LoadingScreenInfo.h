#pragma once
#include "CoreMinimal.h"
#include "EAlwaysLoadedWorlds.h"
#include "LoadingScreenInfo.generated.h"

class ULevelSequence;
USTRUCT(BlueprintType)
struct FLoadingScreenInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ULevelSequence> LevelSequence;
    
    EAlwaysLoadedWorlds World;
    ROGUECORE_API FLoadingScreenInfo();
};
