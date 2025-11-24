#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ReflectiveHitscanHit.generated.h"

class UFSDPhysicalMaterial;
class UPrimitiveComponent;
USTRUCT(BlueprintType)
struct FReflectiveHitscanHit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 BoneIndex;
    FName BoneName;
    FVector_NetQuantize HitLocation;
    FVector_NetQuantizeNormal ImpactNormal;
    UFSDPhysicalMaterial* PhysMat;
    ROGUECORE_API FReflectiveHitscanHit();
};
