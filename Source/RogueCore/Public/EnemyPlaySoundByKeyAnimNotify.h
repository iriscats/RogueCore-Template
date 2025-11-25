#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "EnemyPlaySoundByKeyAnimNotify.generated.h"

class UEnemyPlaySoundKey;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UEnemyPlaySoundByKeyAnimNotify : public UAnimNotify {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyPlaySoundKey* SoundKey;
    
    float VolumeMultiplier;
    float PitchMultiplier;
    uint8 bFollow: 1;
    FName AttachName;
    UEnemyPlaySoundByKeyAnimNotify();
};
