#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXEBlueprintControlledObjective.h"
#include "Templates/SubclassOf.h"
#include "BXELastStageObjective.generated.h"

class AActor;
class ABXERift;
class ABXERiftDetonator;
class UDebrisPositioning;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXELastStageObjective : public UBXEBlueprintControlledObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ABXERift> RiftSpawnClass;
    
    UDebrisPositioning* RiftPositioning;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABXERift* spawnedRift;
    TSubclassOf<AActor> DetonatorSpawnClass;
    UDebrisPositioning* DetonatorPositioning;
    TSoftClassPtr<AActor> ExplosiveLocationClass;
    UDebrisPositioning* ExplosiveLocationPositioning;
    int32 ExplosiveLocationCount;
    float MinDistanceBetweenExplosiveTargets;
    float MaxDistanceFromRiftToDetonator;
    TArray<FVector2D> MinMaxDistanceToDetonator;
    ABXERiftDetonator* SpawnedDetonator;
    TArray<AActor*> Anchors;
    UBXELastStageObjective(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnWiresMerged();
    void InitialGenerationDone();
};
