#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FindPointKeepingDistanceProbe.generated.h"

UCLASS(Blueprintable, NoExport)
class AFindPointKeepingDistanceProbe : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    float MaxDistance;
    AActor* Target;
    float IdealTargetDist;
    AFindPointKeepingDistanceProbe(const FObjectInitializer& ObjectInitializer);
};
