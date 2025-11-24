#pragma once
#include "CoreMinimal.h"
#include "FSDAudioComponent.h"
#include "MotionAudioController.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMotionAudioController : public UFSDAudioComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxValue;
    
    float IncreseSpeed;
    float DecaySpeed;
    bool DebugText;
    bool clamp;
    bool Interp;
    float AccelerationThreshold;
    float SpeedThreshold;
    float FadeInTime;
    float FadeOutTime;
    bool AutoPlayOnSpeedThreshold;
    UMotionAudioController(const FObjectInitializer& ObjectInitializer);
};
