#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "PointRemovedEventDelegate.h"
#include "TerrainDetectInterface.h"
#include "TerrainDetectBoxComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTerrainDetectBoxComponent : public UBoxComponent, public ITerrainDetectInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPointRemovedEvent OnBoxExcavated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartDetectOnBeginPlay;
    bool OnlyDetectOnServer;
    int32 NumCornersToExcavate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 NumCornersExcavated;
    bool KillActorOnPointRemoved;
    UTerrainDetectBoxComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartDetect();
    // Fix for true pure virtual functions not being implemented
};
