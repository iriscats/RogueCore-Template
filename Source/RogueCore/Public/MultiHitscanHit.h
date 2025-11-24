#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "MultiHitscanHit.generated.h"

USTRUCT(BlueprintType)
struct FMultiHitscanHit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 TargetComponentIndex;
    
    uint8 PhysicalMaterialIndex;
    FVector_NetQuantize HitLocation;
    FVector_NetQuantizeNormal ImpactNormal;
    uint8 BoneIndex;
    bool PlayImpactSound;
    bool SpawnDecal;
    float CritRoll;
    ROGUECORE_API FMultiHitscanHit();
};
