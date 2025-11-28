#pragma once
#include "CoreMinimal.h"

#include "GrenadeExplodeOperationData.generated.h"

USTRUCT(BlueprintType)
struct FGrenadeExplodeOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    FVector3f HitPos;
    FVector3f Normal;
    float NormalOffset;
    float NormalSqueeze;
    float Radius;
    float Noise;
    float BurnThickness;
    bool UseBulletBurntMaterial;
    bool DissolvePlatforms;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 OverrideBurntMaterialHandle;
    ROGUECORE_API FGrenadeExplodeOperationData();
};
