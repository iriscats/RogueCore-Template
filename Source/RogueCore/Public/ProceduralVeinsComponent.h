#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/LatentActionManager.h"
#include "EDebrisCarvedType.h"
#include "VeinResource.h"
#include "ProceduralVeinsComponent.generated.h"

class AProceduralSetup;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProceduralVeinsComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVeinResource> VeinResources;
    
    UProceduralVeinsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void GenerateResourceVeins_Async(const AProceduralSetup*& setup, FLatentActionInfo LatentInfo);
    UFUNCTION(BlueprintCallable)
    void GenerateResourceVeins();
    static void GenerateMissingResourceVeins_Async(const AProceduralSetup*& setup, FLatentActionInfo LatentInfo);
    void GenerateMissingResourceVeins();
    static void GenerateDebrisVeins_Async(const AProceduralSetup*& setup, EDebrisCarvedType CarverType, FLatentActionInfo LatentInfo);
    void GenerateDebrisVeins(EDebrisCarvedType CarverType);
    void CountGeneratedResourcesInVeins();
    void CountFinalGeneratedResourcesInVeins();
    void CalculateResourceDistribution();
};
