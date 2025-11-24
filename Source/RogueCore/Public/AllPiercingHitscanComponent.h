#pragma once
#include "CoreMinimal.h"
#include "HitscanComponent.h"
#include "AllPiercingHitscanComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAllPiercingHitscanComponent : public UHitscanComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PiercingDepth;
    
    int32 TracePartitions;
    UAllPiercingHitscanComponent(const FObjectInitializer& ObjectInitializer);
};
