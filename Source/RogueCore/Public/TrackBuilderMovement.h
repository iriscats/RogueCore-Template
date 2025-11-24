#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrackBuilderMovement.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTrackBuilderMovement : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementSpeed;
    
    UTrackBuilderMovement(const FObjectInitializer& ObjectInitializer);
};
