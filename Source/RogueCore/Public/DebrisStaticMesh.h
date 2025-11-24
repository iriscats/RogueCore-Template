#pragma once
#include "CoreMinimal.h"
#include "DecalData.h"
#include "EDebrisMeshCollisionProfile.h"
#include "EDebrisMeshShadows.h"
#include "DebrisStaticMesh.generated.h"

class UFXSystemAsset;
class UMaterialInterface;
class USoundCue;
class UStaticMesh;
USTRUCT(BlueprintType)
struct FDebrisStaticMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* mesh;
    
    UMaterialInterface* Material;
    EDebrisMeshCollisionProfile CollisionProfile;
    float Probablity;
    USoundCue* DestroyedSound;
    UFXSystemAsset* DestroyedParticles;
    FDecalData Decal;
    bool Fragile;
    float ExtraClearRadius;
    EDebrisMeshShadows CastShadows;
    bool Durable;
    int32 SpecialDebrisType;
    bool SpawnWhenCarving;
    bool OnlySpawnWhenCarving;
    ROGUECORE_API FDebrisStaticMesh();
};
