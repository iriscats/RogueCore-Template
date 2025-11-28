#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "SoundAfflictionEffect.generated.h"

class USoundCue;
UCLASS(Blueprintable)
class USoundAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BeginSound;
    
    USoundCue* EndSound;
    bool Attach;
    FName AttachBone;
    float FadeOnLoopEndDuration;
    USoundAfflictionEffect();
};
