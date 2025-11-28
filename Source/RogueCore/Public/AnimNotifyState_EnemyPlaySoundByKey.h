#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_EnemyPlaySoundByKey.generated.h"

class UEnemyPlaySoundKey;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_EnemyPlaySoundByKey : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyPlaySoundKey* SoundKey;
    
    float FadeOut;
    FName SocketName;
    FVector LocationOffset;
    FRotator RotationOffset;
    UAnimNotifyState_EnemyPlaySoundByKey();
};
