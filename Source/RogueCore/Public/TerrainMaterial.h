#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TerrainMaterialCore.h"
#include "TestTerrainMaterialDecalItem.h"
#include "TestTerrainMaterialItem.h"
#include "TerrainMaterial.generated.h"

class UDialogDataAsset;
class UFXSystemAsset;
class UFXSystemComponent;
class UMaterialInstance;
class UObject;
class UResourceData;
class USoundCue;
class UTerrainMaterial;
class UTerrainType;
UCLASS(Blueprintable)
class ROGUECORE_API UTerrainMaterial : public UTerrainMaterialCore {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Collide: 1;
    
    uint8 Diggable: 1;
    uint8 CanBeDrilled: 1;
    uint8 ExplosionProof: 1;
    uint8 MeltsInFire: 1;
    uint8 PlatformDissolvable: 1;
    UResourceData* ResourceData;
    int32 HitsNeededToMine;
    float PickAxeDigSize;
    bool RemoveDebrisOnFirstHit;
    UDialogDataAsset* ShoutLookAt;
    UDialogDataAsset* ShoutOnDig;
    UTerrainType* TerrainType;
protected:
    FText InGameName;
    FText InGameDescription;
    uint8 Precious: 1;
    TSoftObjectPtr<UFXSystemAsset> DigParticles;
    TSoftObjectPtr<UMaterialInstance> DigParticlesMaterialOverride;
    FLinearColor DigParticlesColoOverride;
    TSoftObjectPtr<UFXSystemAsset> PartialDigParticles;
    TSoftObjectPtr<USoundCue> CrumbleSound;
    TSoftObjectPtr<USoundCue> PartialMineSound;
    UTerrainMaterial();
    UFUNCTION(BlueprintCallable)
    static void TestMaterialEffects(UTerrainMaterial* Material, UPARAM(Ref) TArray<FTestTerrainMaterialItem>& Items);
    static void TestDecals(UTerrainMaterial* Material, UPARAM(Ref) TArray<FTestTerrainMaterialDecalItem>& Items);
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
    UFXSystemComponent* SpawnPartialDigParticles(UObject* WorldContextObject, FVector Location, FRotator Rotation) const;
    UFXSystemComponent* SpawnDigParticles(UObject* WorldContextObject, FVector Location, FRotator Rotation, float Density) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrecious() const;
    FText GetInGameName() const;
    UMaterialInstance* GetDigParticlesMaterialOverride() const;
    FLinearColor GetDigParticleColorOverride() const;
};
