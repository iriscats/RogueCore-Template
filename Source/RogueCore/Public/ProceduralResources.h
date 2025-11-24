#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/LatentActionManager.h"
#include "ProceduralResources.generated.h"

class AProceduralSetup;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UProceduralResources : public UActorComponent {
    GENERATED_BODY()
public:
    UProceduralResources(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void GenerateResources();
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void GenerateMissingCarvedResources_Async(const AProceduralSetup*& setup, FLatentActionInfo LatentInfo);
    void GenerateMissingCarvedResources();
    static void GenerateCarvedResources_Async(const AProceduralSetup*& setup, FLatentActionInfo LatentInfo);
    void GenerateCarvedResources();
    void CreateResourcesFromObjectives();
    void CountGeneratedCarvedResources();
    void CountFinalGeneratedCarvedResources();
};
