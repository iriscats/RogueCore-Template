#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OverlapPair.h"
#include "OverlapTrackingSubsystem.generated.h"

UCLASS(Blueprintable)
class UOverlapTrackingSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FOverlapPair> Overlaps;
    
    UOverlapTrackingSubsystem();
};
