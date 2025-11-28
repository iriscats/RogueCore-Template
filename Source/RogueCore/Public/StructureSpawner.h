#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructureSpawner.generated.h"

class AStructureActor;
class UCurveFloat;
class UDebrisPositioning;
UCLASS(Blueprintable)
class AStructureSpawner : public AActor {
    GENERATED_BODY()
    

public:
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
