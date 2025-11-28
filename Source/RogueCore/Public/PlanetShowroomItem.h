#pragma once
#include "CoreMinimal.h"
#include "EPlanetBiomeState.h"
#include "ERunDepth.h"
#include "PlanetPointSetup.h"
#include "ShowroomItem.h"
#include "PlanetShowroomItem.generated.h"

class UAudioComponent;
class UBiome;
class UMaterialInstance;
class UMaterialInterface;
class UStaticMeshComponent;
UCLASS(Blueprintable)
class ROGUECORE_API APlanetShowroomItem : public AShowroomItem {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* NoHoverMaterial;
    
    UMaterialInterface* HoverMaterial;
    UMaterialInterface* NoHoverWhenLockedMaterial;
    UMaterialInterface* HoverWhenLockedMaterial;
    UMaterialInterface* NoHoverWhenUnavailableMaterial;
    UMaterialInterface* HoverWhenUnavailableMaterial;
 
    TArray<UMaterialInstance*> PlanetDepthMaterials;
    TArray<FName> ScalarParametersToCopyFromDepthMat;
    TArray<FName> TextureParametersToCopyFromDepthMat;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPlanetPointSetup HoveredPlanetPoint;
    TArray<FPlanetPointSetup> Points;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> Lines;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PlanetMeshComp;
    ERunDepth SelectedDeptht;
    APlanetShowroomItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateMaterialParameters(ERunDepth Depth);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopAmbienceAudio();
    void StartAmbienceAudio();
    void SetupPlanetPoints(TArray<FPlanetPointSetup> InPoints);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPlanetViewDepth(const ERunDepth Depth);
    void SetHoveredBiome(FPlanetPointSetup Point);
    void OnBiomeHovered(const UBiome* Biome, const EPlanetBiomeState BiomeState);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UAudioComponent* GetDragAudioComponent() const;
};
