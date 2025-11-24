#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTrackingCheatInterface.h"
#include "JetBootsBox.generated.h"

class USpecialEvent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class AJetBootsBox : public AActor, public IActorTrackingCheatInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpecialEvent* SpecialEvent;
    AJetBootsBox(const FObjectInitializer& ObjectInitializer);
    // Fix for true pure virtual functions not being implemented
};
