#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnEffectItem.h"
#include "SpawnEffectsComponent.generated.h"

class UMaterialInstance;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpawnEffectsComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstance* BiomeMaterialOverride;
    
    USpawnEffectsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_AddEffects(const TArray<FSpawnEffectItem>& NewEffects);
};
