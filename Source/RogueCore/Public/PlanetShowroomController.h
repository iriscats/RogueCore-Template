#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ERunDepth.h"
#include "PlanetPointInfo.h"
#include "PlanetPointSetup.h"
#include "ShowroomController.h"
#include "PlanetShowroomController.generated.h"

class APlanetShowroomItem;
class UBiome;
class UCanvasPanelSlot;
class UObject;
class UPlanetShowroomController;
class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlanetShowroomController : public UShowroomController {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    APlanetShowroomItem* PlanetInstance;



    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float DragSmoothingSpeed;

    float PointTargetSmoothingSpeed;

    float AccumulatedDeltaPitch;

    float AccumulatedDeltaYaw;

    TOptional<FQuat> PointTargetRotation;

    UPlanetShowroomController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void SetPlanetViewDepth(const ERunDepth Depth);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlanetShowroomItem* PlanetInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DragSmoothingSpeed;
    float PointTargetSmoothingSpeed;
private:
    float AccumulatedDeltaPitch;
    float AccumulatedDeltaYaw;
    TOptional<FQuat> PointTargetRotation;
    UPlanetShowroomController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPlanetViewDepth(const ERunDepth Depth);
    void SetMapSeed(const int32 Seed);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FPlanetPointInfo> ProjectPointsToScreen(const TArray<USceneComponent*>& Points, UCanvasPanelSlot* canvasSlot) const;
    void LookAtScenePoint(const USceneComponent* Point);
    void HighlightZoneUnderMouse(UCanvasPanelSlot* canvasSlot);
    TMap<UBiome*, FPlanetPointSetup> GetShuffledPlanetPoints(const int32 Seed) const;
    UBiome* GetHighlightedBiome() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UPlanetShowroomController* DisplayPlanet(UObject* WorldContextObject, TSoftClassPtr<APlanetShowroomItem> PlanetActor);
};
