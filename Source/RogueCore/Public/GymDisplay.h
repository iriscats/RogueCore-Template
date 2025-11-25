#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EGymDisplayType.h"
#include "GymDisplay.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API AGymDisplay : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGymDisplayType GymType;
    
    AGymDisplay(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EGymDisplayType GetGymType() const;
};
