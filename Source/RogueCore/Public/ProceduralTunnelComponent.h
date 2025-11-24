#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeightedTunnelDecoration.h"
#include "ProceduralTunnelComponent.generated.h"

class UCaveInfluencer;
class UTunnelParameters;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProceduralTunnelComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTunnelParameters* TunnelParameters;
    
    TArray<FWeightedTunnelDecoration> ForcedFirstTunnelDecorations;
    TArray<FWeightedTunnelDecoration> TunnelDecorations;
    float MaxAngleFromLastPointToEntrance;
    bool CreateDirt;
    UCaveInfluencer* DirtInfluencer;
    float DirtInfluencerRange;
    float MaxDirtRangeToSurface;
    UProceduralTunnelComponent(const FObjectInitializer& ObjectInitializer);
};
