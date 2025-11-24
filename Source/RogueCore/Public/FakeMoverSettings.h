#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DeepPathFinderSize.h"
#include "FakeMoverPropulsion.h"
#include "FakeMoverTarget.h"
#include "FakeMoverSettings.generated.h"

UCLASS(Blueprintable)
class UFakeMoverSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    DeepPathFinderSize PathfinderColiSize;
    
    bool StickToSurface;
    bool AlignRotationToSurface;
    float AirFriction;
    float SurfaceFriction;
    float Gravity;
    float AirGravity;
    FFakeMoverPropulsion Propulsion;
    FFakeMoverTarget NearestPlayerInfluence;
    FFakeMoverTarget TargetInfluence;
    UFakeMoverSettings();
};
