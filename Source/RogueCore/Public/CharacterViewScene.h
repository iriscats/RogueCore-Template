#pragma once
#include "CoreMinimal.h"
#include "CharacterViewInfo.h"
#include "CharacterViewScene.generated.h"

USTRUCT(BlueprintType)
struct FCharacterViewScene {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterViewInfo> Characters;
    
    bool MissionSuccess;
    ROGUECORE_API FCharacterViewScene();
};
