#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructureSpawner.generated.h"

class AStructureActor;
class UCurveFloat;
class UDebrisPositioning;
UCLASS(Blueprintable, NoExport)
class AStructureSpawner : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AStructureActor* StructureInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AStructureActor> SoftStructureClass;
    UDebrisPositioning* DebrisPositioning;
    UCurveFloat* CostCurve;
    int32 MaxSpawnLocationTries;
    bool ShouldRotateTowardsCenterOfRoom;
    AStructureSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TrySpawnStructure();
};
