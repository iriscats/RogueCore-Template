#pragma once
#include "CoreMinimal.h"

#include "DeepPathfinderCharacter.h"
#include "CaveWorm.generated.h"

class AResourceChunk;
class UHealthComponentBase;
class UObject;
class UResourceData;
class USimpleHealthComponent;
UCLASS(Blueprintable, MinimalAPI)
class ACaveWorm : public ADeepPathfinderCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* Health;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SearchChunksRadius;
 
    float SearchChunksInterval;
    ACaveWorm(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static AResourceChunk* SpawnResource(UObject* WorldContext, UResourceData* Data, float Size, FTransform Transform, FVector Impulse, FVector DropOffset);
    UFUNCTION(BlueprintCallable)
    void Search();
    void IncrementKillCount(UHealthComponentBase* HealthComponent);
    void DropResource(UResourceData* Data, float Size, FVector Impulse, FVector DropOffset);
};
