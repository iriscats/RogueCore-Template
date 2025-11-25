#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Steerable.h"
#include "Targetable.h"
#include "PathfinderVehicle.generated.h"

class UDeepPathfinderMovement;
class UHealthComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class APathfinderVehicle : public APawn, public ITargetable, public ISteerable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeepPathfinderMovement* PathfinderMovement;
    
    USkeletalMeshComponent* mesh;
 
    UHealthComponent* HealthComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    APathfinderVehicle(const FObjectInitializer& ObjectInitializer);
    // Fix for true pure virtual functions not being implemented
};
