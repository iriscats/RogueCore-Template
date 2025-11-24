#pragma once
#include "CoreMinimal.h"
#include "CharacterProgress.generated.h"

class UPlayerCharacterID;
USTRUCT(BlueprintType)
struct FCharacterProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* characterID;
    
    int32 Level;
    float Progress;
    int32 CurrentXP;
    int32 NextLevelXP;
    int32 TimesRetired;
    ROGUECORE_API FCharacterProgress();
};
