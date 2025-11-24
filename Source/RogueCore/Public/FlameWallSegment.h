#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlameWallSegment.generated.h"

class USphereComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AFlameWallSegment : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* CollisionComponent;
protected:
    
    AFlameWallSegment(const FObjectInitializer& ObjectInitializer);
};
