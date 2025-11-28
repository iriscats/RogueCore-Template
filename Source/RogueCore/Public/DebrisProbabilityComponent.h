#pragma once
#include "CoreMinimal.h"
#include "DebrisActorComponent.h"
#include "RandRange.h"
#include "DebrisProbabilityComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDebrisProbabilityComponent : public UDebrisActorComponent {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange ProbabilityRange;
    
    bool IsProbabilityShared;
    UDebrisProbabilityComponent(const FObjectInitializer& ObjectInitializer);
};
