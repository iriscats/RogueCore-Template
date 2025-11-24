#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "CarveDoneDelegateDelegate.h"
#include "AutoCarverComponent.generated.h"

class UTerrainMaterialBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAutoCarverComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialBase* TerrainMaterial;
    
    float Frequency;
    float ExpensiveNoise;
    float MinDistanceMoved;
    ECarveFilterType Filter;
    EPreciousMaterialOptions PreciousMaterialAction;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCarveDoneDelegate OnCarveDoneEvent;
    UAutoCarverComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ForceCarve();
};
