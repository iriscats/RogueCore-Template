#pragma once
#include "CoreMinimal.h"
#include "TracerData.generated.h"

class UFXSystemAsset;
class USoundCue;
USTRUCT(BlueprintType)
struct FTracerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* MainParticle;
    
    UFXSystemAsset* TrailParticle;
    float Speed;
    USoundCue* WhizbySound;
    float WhizBySoundCooldown;
    float Offset;
    float MinDistance;
    ROGUECORE_API FTracerData();
};
