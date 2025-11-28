#pragma once
#include "CoreMinimal.h"
#include "CarriableItem.h"
#include "Gem.generated.h"

class UBXEBlueprintControlledObjective;
class UCarriableInstantUsable;
class UResourceData;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AGem : public ACarriableItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCarriableInstantUsable* usable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* ResourceType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEBlueprintControlledObjective* SpawnedByObjective;
    float OverrideResourceAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ResourceAmount;
    bool hasBeenReleased;
 
    AGem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetResourceAmount(float amount);
    void SetHasBeenReleased(bool NewHasBeenReleased);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasBeenReleased() const;
};
