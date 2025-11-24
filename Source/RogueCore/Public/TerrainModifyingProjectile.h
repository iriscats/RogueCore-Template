#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Projectile.h"
#include "RevertToNormalDelegate.h"
#include "TerrainModifyingProjectile.generated.h"

class UStaticMesh;
class UTerrainMaterial;
UCLASS(Blueprintable, NoExport)
class ATerrainModifyingProjectile : public AProjectile {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRevertToNormal OnRevertToNormal;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* Terrain;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* OriginalGroundMaterial;
    UStaticMesh* CarveMesh;
    FVector CarveMeshScale;
    FVector LastHitLocation;
    float Radius;
    bool Revert;
    float TimeOnGround;
    float ExpensiveCarveNoise;
    ATerrainModifyingProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Tick(float DeltaSeconds);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRadius() const;
    void BeginPlay();
};
