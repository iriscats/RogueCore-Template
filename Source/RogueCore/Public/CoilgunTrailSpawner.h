#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "CoilgunTrailSpawner.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UCoilgunTrailSpawner : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> TrailSegmentClass;
    
    float SegmentSpawnInterval;
    float TrailDistance;
    float TrailSegmentInterval;
    float TrailSpawnRange;
    UCoilgunTrailSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnSegment();
};
