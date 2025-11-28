#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlameWallSegment.generated.h"

class USphereComponent;
UCLASS(Abstract, Blueprintable)
class AFlameWallSegment : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* CollisionComponent;
 
    
    AFlameWallSegment(const FObjectInitializer& ObjectInitializer);
};
