#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "ShallowPathfinderMovement.generated.h"

class ASPFCrowdManager;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UShallowPathfinderMovement : public UPawnMovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementSpeed;
    
    float AvoidanceRadius;
    float CoherenceRadius;
 
    ASPFCrowdManager* CrowdManager;
    UShallowPathfinderMovement(const FObjectInitializer& ObjectInitializer);
};
