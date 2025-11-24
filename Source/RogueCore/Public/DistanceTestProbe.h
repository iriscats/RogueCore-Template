#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DistanceTestProbe.generated.h"

UCLASS(Blueprintable, NoExport)
class ADistanceTestProbe : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    int32 NumX;
    int32 NumY;
    float DeltaX;
    float DeltaY;
    ADistanceTestProbe(const FObjectInitializer& ObjectInitializer);
};
