#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeatMaterialComponent.generated.h"

class UMaterialInstanceDynamic;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHeatMaterialComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    float MaxEffect;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> MaterialIntances;
    UHeatMaterialComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTemperatureChanged(float temperature, bool overheated);
    void AddHeatMaterial(UMaterialInstanceDynamic* MaterialInstance);
};
