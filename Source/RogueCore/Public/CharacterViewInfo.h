#pragma once
#include "CoreMinimal.h"
#include "EquippedVanity.h"
#include "Templates/SubclassOf.h"
#include "CharacterViewInfo.generated.h"

class APlayerCharacter;
class UVictoryPose;
USTRUCT(BlueprintType)
struct FCharacterViewInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APlayerCharacter> CharacterClass;
    
    FEquippedVanity EquippedVanity;
    bool SurvivedInPod;
    UVictoryPose* VictoryPose;
    ROGUECORE_API FCharacterViewInfo();
};
